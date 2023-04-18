![](https://GalacticProps.co.uk/GitHub/Blaster_Scope/GitHub_Logo.jpg)


------------

##### *Table of Contents*
- [Arduino E-11 Animated Blaster Scope](#arduino-e-11-animated-blaster-scope)
- [Video of the Prototype](#video-of-the-prototype)
- [Parts Required](#parts-required)
- [Software Required](#software-required)
- [Wiring Schematics](#wiring-schematics)
- [Programming Instructions](#programming-instructions)
- [3D Print STL Files](#3d-print-stl-files)
- [Licence](#licence)
- [Donation Button](#donation-button)

### Arduino E-11 Animated Blaster Scope

Arduino code and STL files for an animated Star Wars E-11 Blaster Scope with optional Red Dot Laser Sight. 
This is a very basic build just to add some functionality to your Star Wars Blaster Scope.
Easy to build with only minimal wiring required using cheap and readily available parts. 
The 3D STL files to print the E-11 Blaster Scope to fit these electronics are included in the Download.

If you looking for changeable Screen Displays on your Scope check out my - [E-11 V2.0 Scope Kit](https://proptronix.co.uk/prop-electronics/e-11-v2-scope-add-on-kit "PropTroniX")

![](https://www.galacticprops.co.uk/GitHub/Blaster_Scope/GitHub_Scope_1.png)

![](https://www.galacticprops.co.uk/GitHub/Blaster_Scope/GitHub_Scope_2.png)

### Video of the Prototype

Check out my Video of a 3D Printed Prototype with the Electronics Installed

YouTube Video - [Star Wars E-11 Blaster Scope with Electronics](https://youtu.be/OtV69T4YZjw "Star Wars E-11 Blaster Scope with Electronics")


###  Parts Required

1 x Set of 3D STLFiles  - For 3D Printing the E-11 Blaster Scope (Included FREE in the Download)

1 x [DFRobot Beetle](https://proptronix.co.uk/arduino_components/microcontrollers/dfrobot-beetle "DFRobot Beetle") - ATmega32u4 V 16MHz Micro USB 

1 x [Red Laser Dot Diode](https://proptronix.co.uk/arduino_components/leds/red-dot-laser-diode-led "Red Laser Dot Diode") - 650nm 6mm 3V-5V (Optional)

1 x[ 0.49 OLED Display](https://proptronix.co.uk/arduino_components/oled_displays/0-49-oled-display " 0.49 OLED Display") - White OLED Screen Module SSD1306 Drive IC 64 x 32 IIC Interface

1 x [6mm Tactile Momentary Switch](https://proptronix.co.uk/other_components/switches/6mm-tactile-switch "6mm Tactile Momentary Switch") - 2 Pin SPDT Momentary Tactile Pushbutton Switch 6mm x 6mm x 5mm (Optional)

1 x [10K Ω Resistor ](https://proptronix.co.uk/other_components/resistors/1-4w-carbon-film-resistors "10K Ω Resistor ")- 1/4W 5% Carbon Resistors - Used on the ON/Button for the Red Dot Laser

1 x [4-Pin Micro JST Cable](https://proptronix.co.uk/other_components/connectors/micro-jst-1-25mm-m-f "4-Pin Micro JST Cable") - (Male & female) For Connecting OLED Screen to DFRobot Beetle

1 x [3-Pin Micro JST Cable](https://proptronix.co.uk/other_components/connectors/micro-jst-1-25mm-m-f "3-Pin Micro JST Cable") - (Male & female) For Connecting Red Dot Laser Switch to DFRobot Beetle

2 x [2-Pin Micro JST Cable](https://proptronix.co.uk/other_components/connectors/micro-jst-1-25mm-m-f "3-Pin Micro JST Cable") - (Male & female) For Connecting Red Dot Laser Diode to DFRobot Beetle & to supply 5V Power to the DFRobot Beetle

3 x [M2 Slotted Cheese Head Machine Screws](https://proptronix.co.uk/accessories/screws-nuts-and-bolts/e-11-scope-front-screws "M2 Slotted Cheese Head Machine Screws") - For the Front of the Scope

2 x [4x3mm Neodymium Magnets](https://proptronix.co.uk/other_components/magnets/blaster-scope-magnets "4x3mm Neodymium Magnets") - To Hold the Screen Holder in Place inside the Scope

1 x [30mm Round Glass Cabochon ](https://proptronix.co.uk/accessories/round-glass-cabochon "30mm Round Glass Cabochon ")- Used as a Magnifier Lens for the Scope Eye Piece

All parts listed above are available from my Online Shop , eBay, Amazon or AliExpress.

I also sell an updated [E-11 Blaster Scope Electronics ](https://proptronix.co.uk/prop-electronics/blaster-scope-electronics-kit "E-11 Blaster Scope Electronics ")as a Self Build Kit in my Shop. It has changeable displays and improved code and also includes the specially designed STL Files for the Kit.

###  Software Required

You will need the following Software & Libraries to install and setup the Scope Arduino Code on the DFRobot Beetle.
- The latest version of Arduino IDE - [Download from the Arduino Site](https://www.arduino.cc/en/Main/Software "Download from the Arduino Site")

Arduino Libraries Needed:

- WIRE - Pre-Installed with Arduino IDE
- SPI - Pre-Installed with Arduino IDE
- Adafruit GFX - Included in the Download
- Adafruit SSD1306 - Included in the download and Pre-Set for 64x32 OLED Display

SCTroniX V1.0 Arduino E-11 Scope Code:

- Arduino_Blaster_Scope-V1.0.ino - Included in the Download

###  Wiring Schematics

![](https://galacticprops.co.uk/GitHub/Blaster_Scope/GitHub_Scope_Wiring.png)

###  Programming Instructions

1. Copy the Two Included Libraries (Adafruit_GFX_Library & Adafruit_SSD1306-master_64x32) into your Arduino Libraries Folder.

2. Run the Arduino IDE Application

3. File Open and locate the Arduino-Blaster-Scope-V1.0 Directory and open the Load the Arduino_Blaster_Scope-V1.0.ino file.

4. Select Tools: Board: and Arduino Leonardo

5. Select Tools: Port: and Select the COM Port your DFRobot Beetle board is plugged in to.

6. Select Tools: Programmer: and choose AVRISP mkII.

7. Upload the Arduino_Blaster_Scope-V1.0.ino code to the board

You should now have a functioning Blaster Scope

### 3D Print STL Files
The download also includes a set of E-11 Blaster Scope 3D Printable STL Files. These are modified from the Free Files that are available from [My Mini Factory](https://www.myminifactory.com/object/3d-print-star-wars-storm-trooper-blastech-e-11-blaster-rifle-by-blaster-master-72283 "My Mini Factory") by Raymond Hebert.

![](https://www.galacticprops.co.uk/GitHub/Blaster_Scope/GitHub_Scope_4.png)

###  Licence

This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
To view a copy of this license, visit https://creativecommons.org/licenses/by-nc/4.0/


### Donation Button
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate/?hosted_button_id=PEK9F5JV4Q6NL) Please feel free to donate a cup of coffee if you find this code useful. Thank You
