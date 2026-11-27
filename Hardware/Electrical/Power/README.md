This is the circuit which turns power to one coil on or off. Below are some pictures and descriptions of the parts on the PCB.
The most important part is the high-power MOSFET which is a type of transistor switch. This particular design uses Goford brand MOSFET, product code GT020N10TL, which is rated to 100V drain-to-source and 300A continuous current, although it can briefly handle higher currents if done infrequently.
The next most important part is the MOSFET gate driver IC which helps quickly and safely make the MOSFET conductive or not, corresponding to the coil being powered "on" or "off" respectively. It also provides galvanic isolation between the low-voltage control circuitry and higher-voltage main power rails for safety. Accordingly, it has its own +15V isolated power supply located on another board (not shown below) and plugged into one of the connectors. Each board has two power supply input connectors so they can be daisy-chained together and use less wire.
Another important part is the flyback diode (also called crowbar diode) which lets the coil current continue flowing briefly after it is shut off (disconnected from main power) and dissipate its energy through its own wire resistance. Without this component, there would be a huge inductive voltage spike across the MOSFET when it tries to stop conducting, which could easily cause breakdown and destroy it.
This version of the circuit uses only low-side switching to reduce the cost and complexity of having to switch an N-channel MOSFET at the high side or having to find a corresponding P-channel MOSFET with similar power ratings.

Front view:
![[power switch board front labeled.png]]

Back view:
![[power switch board back labeled.png]]

The board could technically be facing in any direction as long as the terminal connections to the coil and power are correct. The "front" and "rear" are just nominal designations.