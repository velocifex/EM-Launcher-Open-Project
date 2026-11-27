The coilgun is mainly a sequence of individual stage assemblies that are then attached together. Each stage assembly has a main frame, a coil (on its bobbin), a power switching board for that coil, and a sensor. Each of those parts attaches to the main stage frame with M3 fasteners.
Each stage assembly is secured to the aluminum T-slot rail "backbone" with M5 threaded T-slot nut and any bolt of choice.

Here is a sequence of images showing the assembly of one stage, although the parts can be attached in any order:
1. Bare main-frame of the stage, shown from the front i.e. the part that faces the muzzle.![](step%201.jpg)
2. Added the coil, it attaches to the front face as so:![](step%202.jpg)
3. Added the power switch board, also attaches to the front face. The coil is attached with its yellow wire to positive and purple wire to negative.![](step%203%20front.jpg)![](step%203%20rear.jpg)
4. Added the sensor, which attaches to the rear face and the contacts fit into the slot in the frame like this:![](step%204.jpg)
5. That individual stage is now complete. It can be attached to the T-slot rail with appropriate T-slot nuts:![](step%205%20front.jpg)![](step%205%20rear.jpg)
6. Repeat the above steps to assemble all stages and stack them along the rail, so the coils and frames form a continuous barrel.

Aside from that, the power busbars can be attached to the T-slot rail with their mounting arms and more M5 T-slot nuts and bolts. Then the power switch boards for each stage and the capacitors can be connected to the power busbars like so:
![](connecting%20coil%20and%20capacitor%20to%20busbars.png)

**Editor's note: Time ran out here so not all parts got a good assembly explanation. But that should be ok because this prototype isn't meant to be built by others, it's just meant to be shown how it worked so it can be improved upon. And the coil parameters and sensor circuits are the real only important thing to improve anyways.**
Notes about hooking up power (this is hasty, incomplete, and unorganized sorry):
- 12V from a power supply unit intended for LEDs powers the following converters:
	- Two 12V to 15V isolated DC-DC converters, one each for the sensor power daisy-chain and MOSFET board daisy-chain.
	- 12V to 5V DC-DC converter for the control circuitry i.e. microcontroller and shift register.
- Spare AC-DC converter powers the capacitor charger. The voltage and power rating depend on the charger device and its power draw, but so far a random 12V 6A (72W DC) power brick has worked. A separate (like, different wall plug) power supply is used for the capacitor charger because:
	- The inexpensive charger I bought has bad noise on the 12V input power lines when it charges.
- If an electrically-isolated, low-noise charger was used then it could be powered from the same 12V supply that the other parts are.
