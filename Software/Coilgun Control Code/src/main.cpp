#include <Arduino.h>
#include <Wire.h>
// Program for closed-loop control of coilgun. Reads from sensors between stages
// and sends signal to the power switch drivers to turn on/off coils.

// microcontroller pin constants
// fire button pin
const int FIRE_BUTTON = A0;
// shift register serial input pin
const int SHREG_IN = 2;
// shift register clock pin
const int SHREG_CLK = 3;
// shift register active-low reset/clear pin
const int SHREG_RST = 4;

// enum to represent coil state, whether ready to fire, firing, or done firing
enum coil_state_enum {ready, firing, done};

// struct to contain information of a coil, namely pin number to driver
// and its individual time delay (maximum firing duration)
struct coil {
    // in this version of the code, this will be the END sensor not the BEGINNING sensor for a stage
    int sensor_pin = -1;//which pin the gate sensor for this is, -1 for none attached
    coil_state_enum coil_state = ready;
    int timedelay = 20000;//microseconds, for allowing custom time delays per stage
    unsigned long time_started_firing;//microseconds, for keeping track of how long coil has been on
};

// constant total number of coils
const int NUM_COILS = 8;
// array to hold all the coil structs
coil coils[NUM_COILS];


void delayWellBehaved(unsigned long dt) {
    // must decide whether to use delay() or delayMicroseconds() because the latter
    // may misbehave with time delay over 16383 us according to official docs.
    if (dt < 10000) {
        delayMicroseconds(dt);
    }
    else {
        // microsecond precision wont be important for delays > 10ms.
        delay(dt / 1000);
    }
}

void resetShiftRegister() {
    // reset the shift register by setting its clear pin low, waiting, then high again.
    digitalWrite(SHREG_RST, LOW);
    delay(10);
    digitalWrite(SHREG_RST, HIGH);
    return;
}

void pulseClock() {
    // pulse the clock pin of the shift register,
    // which activates on low->high transition.
    // max allowable frequency is like 36MHz so a 1us delay is fine.
    digitalWrite(SHREG_CLK, LOW);
    delayMicroseconds(1);
    digitalWrite(SHREG_CLK, HIGH);
    return;
}

// very simple timer to tell when it's timed out,
// returns TRUE when time is done, FALSE if time not done.
// note that this does not use the delayMicroseconds() so it is not susceptible
// to the problem with that function if delay time is > 16000 or whatever
bool simpleTimeoutTimerMicros(unsigned long start_t, unsigned long max_duration)
{
    // return true if the current time in microseconds is past
    // the max duration time after the start time
    if (micros() > (start_t + max_duration))
    {
        return true;
    }
    // in the rare case where the continuously counting up timer overflows
    // during this timer, just return true. This will make it a shorter-than-
    // normal timeout but at least it's safe from having longer-timeout problems.
    else if (micros() < start_t)
    {
        return true;
    }
    // false by default meaning the timer has not timed out
    return false;
}

// function to reset all the coils states to "ready"
void resetCoils()
{
    for (int i = 0; i < NUM_COILS; i++)
    {
        coils[i].coil_state = ready;
    }
}

void setup() {
    pinMode(FIRE_BUTTON, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);

    // only used for debugging
    Serial.begin(38400);

    // initialize shift register pins
    pinMode(SHREG_IN, OUTPUT);
    pinMode(SHREG_CLK, OUTPUT);
    pinMode(SHREG_RST, OUTPUT);
    // reset shift register to properly initialize it
    resetShiftRegister();
    // shift register clock moves data in when transition low->high, so start it low
    digitalWrite(SHREG_CLK, LOW);

    // initialize/define the coils details
    // currently no custom maximum time for each coil is set
    coils[0].sensor_pin = 12;
    coils[1].sensor_pin = 11;
    coils[2].sensor_pin = 10;
    coils[3].sensor_pin = 9;
    coils[4].sensor_pin = 8;
    coils[5].sensor_pin = 7;
    coils[6].sensor_pin = 6;
    coils[7].sensor_pin = 5;
    resetCoils();
    // set arduino pinmode for all those pin numbers as input pullup
    for (int i = 0; i < NUM_COILS; i++)
    {
        pinMode(coils[i].sensor_pin, INPUT_PULLUP);
    }
}

void loop() {
    // code to perform firing sequence:
    if ((digitalRead(FIRE_BUTTON) == LOW) && (NUM_COILS > 0)) // low when button is pressed
    {
        // firing indicator led goes on
        digitalWrite(LED_BUILTIN, HIGH);//this also (formerly) turns on the stopper electromagnets

        // put a 1 in the start of the shift register just once, it will be cycled through the
        // registers with every clock pulse, and input stays 0 for the rest of firing.
        digitalWrite(SHREG_IN, HIGH);
        // pulse the clock to make the input go into the first register, firing first coil
        pulseClock();

        // loop through coils and turn one high then low for its duration
        for (int i = 0; i < NUM_COILS; i++) {
            // if coil state is "ready", then set to "firing" and set the fire start time
            if (coils[i].coil_state == ready)
            {
                coils[i].coil_state = firing;
                coils[i].time_started_firing = micros();
            }
            else { break; }//if it's not ready then break out

            // check if this coil has a sensor pin set, and cancel firing if not.
            if (coils[i].sensor_pin < 0)
            {
                break;
            }

            // in this version of the code, the sensor gate is at the END of each stage,
            // and the timer is an emergency timeout timer rather than a typical timer.
            // so we will wait until the end-of-stage sensor is tripped before proceeding.
            while ((not simpleTimeoutTimerMicros(coils[i].time_started_firing, coils[i].timedelay))
            and
            (digitalRead(coils[i].sensor_pin) == HIGH))//this sensor is HIGH when projectile is NOT in it
            {
                //TODO...nothing just wait and coil is on?
                //delayMicroseconds(1);
            }

            // at this point the coil stage finished firing, so set it to "done" state
            coils[i].coil_state = done;

            // (repeatedly) make the shift register input low after the first input
            digitalWrite(SHREG_IN, LOW);

            // pulse the clock to cycle the 1 in the register to the next coil
            pulseClock();
        }

        // immediately reset the shift register after firing is finished
        resetShiftRegister();

        // and reset the coil states
        resetCoils();

        //debouncing and (formerly) keeping stopper electromagnets on.
        delay(500);

        // firing finished, turn indicator led off
        digitalWrite(LED_BUILTIN, LOW);
    }
    else // when fire button not pressed
    {
       resetShiftRegister();
    }
}
