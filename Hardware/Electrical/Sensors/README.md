Initially there were IR photogate sensors made to detect projectile position, shown below:
![[photo gate type sensor.png]]

But those did not work consistently for some reason, so a simpler direct-contact sensor was made, shown below:
![[direct contact type sensor.png]]
It has two small flexible "brushes" made from copper braided desoldering wick, and when the projectile enters the sensor it just contacts them both and closes a circuit.

There are a few more circuit components, shown in the KiCad schematic in the "sensor circuit" folder, just to electrically isolate the sensitive microcontroller circuitry from the parts of the sensor that are near the coils and susceptible to the huge EMF spikes when it turns on or off. This additional circuitry is shown in the schematic in this folder.
Like the power boards, the sensors have a +15V isolated power supply located on another board and plugged into one of the connectors. Each board has two power supply input connectors so they can be daisy-chained together and use less wire.

The simple contact sensor has worked fine so far, but it likely will not hold up at higher velocities. A new sensor circuit will be needed, and while photogates are well-known, an inductive sensor is probably a more compact and possibly more accurate solution. Inductive sensing may not even need a separate sensor-coil, it could work on the force-exerting coils when they are not yet turned on. A similar design exists in rotary electric motors called "field-oriented control" or FOC.