These are almost all the solid parts that hold the coils, circuits, and everything else. The only thing not included is the part that holds the capacitor in place, because that is highly specific to a particular capacitor model and dimensions.
All parts can be 3d printed except for an aluminum 30mm x 30mm T-slot extruded rail, which forms the solid backbone of the whole assembly.

- An aluminum extrusion T-slot rail, 30mm by 30mm square, is the main backbone of the whole structure as mentioned above. Several other 3D printed parts attach to this with M5 T-slot nuts and any sort of M5 bolt. It is oriented at a 45 degree angle and all parts connect to it that way, so they naturally get centered if they need to be.![](aluminum%20t%20slot%20rail%20pic%20in%20freecad.png)

- This flat, vertical "main" frame holds the coil bobbins, the sensors, and the power switch PCB of a single stage all together. It has alignment holes for putting fasteners through to make sure all the adjacent stages of "barrel" (the insides of each coil bobbin) are aligned. There are also slots for the brushes of the contact sensors to protrude into the barrel area.![](main%20frame%20pic.png)

- The bobbin is a structure around which each electromagnet coil is wound. It also serves as a segment of "barrel" for the projectile to slide through.![](coil%20bobbin%20pic.png)Example in real life with the coil wound around it (ignore the little triangular notches at the top of the bobbin, those were used for aligning coils in an earlier design version):![](coil%20wound%20on%20bobbin.jpg)

- The frame of the sensor is self-explanatory. It has one hole to attach to the main frame.![](contact%20sensor%20frame%20pic.png)Example of an assembled one in real life:![](direct%20contact%20type%20sensor.png)

- The "loading breech" is where the projectile sits when it is ready to fire. It aligns with the coils in the same way they do with each other.![](loading%20track%20pic.png)

- These feet attach to the bottom of the T-slot rail to stabilize it.![](stabilizer%20foot%20pic.png)

- These mounting arms hold the two power busbars, which efficiently distribute current from the positive and negative terminals of the capacitor(s) to each coil stage's power switch.![](power%20busbar%20mounts%20pic.png)

- Finally, these flat supports stick out far to the sides of the rail and can hold any loose items closer to the coils and other electronics. For example, they can hold the control circuit board so the wires connecting it and the other electronics can be shorter.![](misc%20electronics%20holding%20frame%20pic.png)

Additional notes:
- Pretty much everything uses M3 fasteners (3mm holes) except for the attachment to the 3030 T-slot rail which are M5 bolts and T-slot nuts (5mm holes).
- The coil bobbin's height can be simply modified by a variable in the FreeCAD file. The default will be kept at a somewhat arbitrary 20mm long for the foreseeable future, try not to change that until a more well-proven value (for a given projectile length) is established.
