This part receives signals from the projectile position sensors and sends signals to the coil power boards. The current design uses a microcontroller (clone of Arduino Nano) and an 8-bit shift register (SN74LS164N). The whole board uses +5V power and also 5V logic. The Nano is able to handle 5V logic BUT not necessarily other microcontrollers!

A simple explanation of the control algorithm during firing is as follows:
1. The fire button is pressed while the projectile is in the "breech" or "loading area", just in front of the first coil.
2. The microcontroller sends a high signal to the input pin of the shift register.
	- Specific to the SN74LS164N, there are two input pins which get AND operated together, but here one of those is connected to the positive supply voltage so it's always high.
3. The microcontroller sends a 1 microsecond pulse to the clock pin of the shift register.
4. The microcontroller sends a low signal to the input pin of the shift register (if it was not low already).
5. The first coil is turned on by the corresponding output pin on the shift register and pulls the projectile in, towards its center.
6. Simultaneously, the microcontroller starts a timeout timer to track how long this coil has been on.
7. The coil stays on until either of the following happens:
	1. The projectile reaches and activates the next sensor.
	2. The safety timer reaches its preprogrammed limit and "times out".
8. If this is NOT the last coil stage, then repeat steps 3 through 7.
9. If this is the last coil stage, pulse the (active-low) clear pin on the shift register to (re)set all the coils to off.

Below is an picture of the existing circuit and the most important parts of it labeled. The one important part not shown here is the "trigger" button to tell it to fire, which simply connects to two of the microcontroller pins.
![[microcontroller board explained pic.png]]

A more complete schematic of the circuit is shown in the KiCad project sub-folder in this same folder.

An alternative way to do control could be to have a very simple circuit with logic ICs on each stage. The logic is essentially a reset-dominant SR latch, ideally with a rising-edge trigger for the input to start the coil firing. The logic circuit is illustrated below:
![[logic circuit for simple coil stage control.png]]
A separate timeout circuit could also be added for safety. It would take in the same signal as the coil turn-on input and output to an additional OR gate that also takes in the sensor output. The output of the OR gate would go to the coil turn-off input of the logic board.
