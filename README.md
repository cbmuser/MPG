# MPG

![](http://www.cbmhardware.de/git/axis_arduino.jpg)


Use three BC337 (NPN) to switch Axis (1 Port toggle) and Feedrate (2 Ports mux): 
 

     Mach3 Port ---c b e ---[2k2]--GND
                     |
                     _
                     2
                     k
                     2 
                     -
                     |
                Arduino-Port
             
 Jogwheel
 Mach3
 A low  : Pin 10
 B high : Pin 11
 VCC    : PC 5V
 GND    : 0V
 GND also to GND under P15
 
  
 # Arduino
 
 Digital 2, 3, 6 : switching transistors (see source)
 Digital 4,5 : Inputs for Buttons Axis and Feedrate to GND
 
 **Couple all GND, Arduino and Mach3 together !**
 
 The blue display is 1602 at I²C.
 
 
 
![]( http://www.cbmhardware.de/git/axis.jpg)

It works !
 
