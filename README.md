# Open-Source Electromagnetic Launcher (Coilgun) Development
This is a project to continually improve and implement open-source designs for coilguns, which are a type of electromagnetic (E.M.) launcher. This repository has files and information about the hardware and software for the designs under development.

# Help Wanted!
>This repo currently encapsulates a working but underperforming prototype. **It is meant as a starting point to improve upon.**
>It would be very helpful if individuals with electrical engineering skills could contribute to the project, especially to improve the circuit design (both schematics and layout).
>As stated below, **"this coilgun project aims to become the long-developed, widespread project that always could have been, but sadly never was."**

# Legality Notice
Physically producing some parts of this project may be legally prohibited in some jurisdictions. Please be aware of any laws that may apply to you before participating in this project in any way.

# Overview Explanation
Here is one very good and quick explanation of coilguns:
https://www.youtube.com/shorts/EF3v-DWCZcQ

In summary, a coilgun is fundamentally a type of electromagnetic motor, a linear switched reluctance motor to be exact. Like other electric motors it has:
- An armature to be moved. On rotating motors this is the rotor, and on a coilgun it is the projectile or launch vehicle.
	- For most coilguns including this one, the projectile is made partly or entirely of ferromagnetic material.
- Electromagnets to exert a force. On rotating motors this is the stator, while on a coilgun they are arranged along the launch track or "barrel".
	- For most coilguns including this one, these are solenoids. Usually the cross-sectional shape is circular, but this project has experimented with flat-plate rectangles as well.
	- There are usually sets of coils connected as a "phase" in rotating motors, while in coilguns there is usually one coil per "stage".
- Sensors to detect the position of the armature so the right coil(s) can be turned on or off.
- Control circuitry to switch power to specific coils on or off. This could be simply hooking up the coils' switches directly to the sensors in some ways, or using a microcontroller to have more complex switching behavior.
	- In this coilgun project, a microcontroller has been used so far, but a more simple logic circuit could be developed.

# Contents
This repo has files and instructions to do or make the following to construct the current (starting) version of the prototype:
- PCBs from online prototyping services for parts like the power switching circuits. These are in the "Hardware/Electrical" folder.
- Circuits on soldered or solderless prototyping boards for other parts that do not have or need PCBs. These are also in the "Hardware/Electrical" folder.
- 3D print the structural parts like the bobbins for the electromagnet coils. These are in the "Hardware/Mechanical" folder.
- Program microcontrollers to read sensors and switch the coils on or off. These are in the "Software" folder.
To reiterate: this prototype is just the most recent one in development, it has not yet fully achieved the project goal. The information provided in this repo is mainly to see how it was designed, so that it may be improved.

# Goals and Progress
The first milestone goal of this project is to make a coilgun which can launch something with **100m/s speed** and preferably as close to **100J kinetic energy** as possible.
Ideally it should be as energy-efficient as possible too, to make the design feasible to scale up or implement in any real-world use case.

Tests of this repo's developmental prototype as of November 14, 2026 have only achieved about 20m/s with a 44g (.044kg) projectile, giving about 8.8J of kinetic energy. This is about 9% efficient, which is above average for coilgun designs.

The project goal is proven to be feasible with existing commodity components! Several academic and hobbyist/amateur designs have already achieved such performance, but were never made open-source or otherwise did not see further development or community participation. **This coilgun project aims to become the long-developed, widespread project that always could have been, but sadly never was.**

# Possible Next Steps
- **Optimize coil geometry** i.e. wire diameter and number of turns, and consequently its electrical characteristics i.e. inductance and resistance, to create the most force! While also being decently efficient.
	- This is really the main problem to solve for a coilgun!
	- A technique for optimizing the coils has been developed, but it should be scrutinized by others. It's also very technical so it will not be repeated right here.
- Better projectile position sensors, preferably based on inductive sensing.
	- There could be a separate sensor coil in place of the existing photo-gate or contact sensors now, or sensing could be tried on the drive coils themselves.
- Change the control circuit to a simple logic-gate circuit that each stage has a copy of.
	- Would not directly improve efficiency but might make scaling up the number of stages easier.
- Capacitor energy recovery after coils shut off.
	- This would likely require high and low side switching of power to the coils which adds complexity to the power circuit design.
- Gate drive transformer for the power transistors instead of gate driver ICs.
	- This could help simplify the power switching circuit design, especially if it is going to be changed to high and low side switching.
- Set up a simulation to test lots of coil shapes more quickly than building them physically.
	- FreeCAD and ElmerFEM together would work great for this.
- Try different projectile shapes like the typical cylinder or maybe hollow ring/tube. The coils' cross-sectional shape would be different but the strategy to optimize them would be the same.
	- All existing switching and sensing components could be reused regardless of coil shape.

# Other Good Coilgun Projects
- Levi Janssen
	- Youtube channel: https://www.youtube.com/c/LeviJanssen
	- Series of videos about coilgun design:
		- https://www.youtube.com/watch?v=Xh28YdN8uP0&list=PLKl_Ihtuj1fpWz5WA09WJIgf677wJ2ihX (playlist)
		- https://www.youtube.com/watch?v=n-MfA9tIX5s and https://www.youtube.com/watch?v=OzI8P56p3pk (these last two videos in the series aren't in the above playlist)
- Electronoobs
	- Youtube channel: https://www.youtube.com/@ELECTRONOOBS/featured
	- Some videos on his coilgun projects:
		- https://www.youtube.com/watch?v=bGfrwBl-Q-A
		- https://www.youtube.com/watch?v=vtoWxGVx5kA
- OwenAir8242
	- Youtube channel: https://www.youtube.com/@owenair8242
	- This channel has some very good performing coilguns that achieve the 100m/s goal:
		- https://www.youtube.com/watch?v=5a4ZcsGYLRs
		- https://www.youtube.com/shorts/ZIMWo178rbU
		- https://www.youtube.com/shorts/G4_D2fhIGVg
- Tokamake
	- Youtube channel: https://www.youtube.com/@Tokamake
	- There are some excellently performing coilguns on this channel, including ones that much exceed the 100m/s speed goal! For example:
		- https://www.youtube.com/shorts/MI6NMF4MVIE
		- https://www.youtube.com/shorts/5vRxPeuDqeQ
		- https://www.youtube.com/shorts/phLoA5XnM9Y
- Owen Welsh
	- Youtube channel: https://www.youtube.com/@owensprojects
	- Some videos on his coilgun projects:
		- https://www.youtube.com/watch?v=BBhZLNdyRro
		- https://www.youtube.com/watch?v=rotrRg4ZUpk
		- https://www.youtube.com/watch?v=9OQUBITIkow
