/*
   Blaster-Scope-V1.0

   Released on GitHub: 12th April 2023
   Author:    PropTroniX (info@proptronix.co.uk)
   Source :   https://github.com/PropTroniX/E-11-Blaster-Scope-Electronics
   Description: Animated Reticle for the E-11 Star Wars Blaster.

   Electronics Parts Available at www.proptronix.co.uk
   E-11 Blaster Scope STL Files are Included FREE in the GitHub.

   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
   To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

   Thanks goes to Paul Whitrow of TRamp (https://www.facebook.com/trooperamp/)
   for the idea to create this Animated Blaster Scope.
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 12              // Reset OLED Display
#define BARGRAPHSPEED 75           // Bargraph Animation Speed
#define DOTSSPEED 200              // Twin Dot Animation Speed
#define SQUARESSPEED 50            // Flashing Squares Animation Speed
#define RANDOMNUMBERSSPEED 50      // Top Random Numbers Animation Speed
#define RANDOMNUMBERSSPEED2 400    // Botton Random Numbers Animation Speed

#include <Fonts/TomThumb.h>        // Font Needed for the OLED Display

Adafruit_SSD1306 display(OLED_RESET);

long randNumber;                    //Random Numbers Top
long randNumber2;                   //Random Numbers Bottom
uint32_t lastmomentdots;
uint32_t lastmomentsquares;
uint32_t lastmomentbargraph;
uint32_t lastmomentnumbers;
uint32_t lastmomentnumbers2;
uint8_t twindotstate=0,flashsquarestate=0,bargraphstate=0,randomnumbersstate=0,randomnumbers2state=0;

int xmax=64;             // max length x-axis
int ymax=32;             // max length y-axis
int xcenter=xmax/2.0;    // center of x-axis
int ycenter=ymax/2.1;    // center of y-axis
int arc=ymax/2;                                                              
int p, m,a=5;            // a= Needle Speed
int xx=0, oldx=0,oldy=0; 

// Start Laser
int inPin = 11;                  // Laser On/Off Button Pin
int outPin = 9;                  // Laser LED Pin
int stateoutPin = LOW;           // Laser
int stateButton;                 // Laser
int previouslaser = LOW;         // Laser
int state = LOW;                 // the current state of the output pin
int reading;                     // the current reading from the input pin
int previous = HIGH;             // the previous reading from the input pin
long debounce = 200; 
long time=0;
// End Laser

// ------------------------------------------------- Void Radar() ------------------------------------------
void radar(uint8_t angle) {

// Start Draw the Needle  
    float x1=sin(2*angle*2*3.14/100);   // needle position
    float y1=cos(2*angle*2*3.14/100);   // a more accurate calculation would be "cos(DEG_TO_RAD*angle)"
    display.drawLine(xcenter, ycenter, xcenter+oldx, ycenter-oldy, BLACK);  // overdraw the old line
    oldx=arc*x1;   // calculate the new values and store them
    oldy=arc*y1;   // variable names are now not complete explanatory since we use them for the new drawing 
                   // as well, but this is the least calculations
    display.drawLine(xcenter, ycenter, xcenter+oldx, ycenter-oldy, WHITE);  // draw the new line
// End Draw the Needle   
 
// Start of Reticle       
    display.fillCircle (32, 15, 2, WHITE);   // Middle Circle
    display.drawCircle (32, 15, 12, WHITE);  // Outer Circle
      
    display.drawLine (32, 0, 32, 8, WHITE);   // Top Line
    display.drawLine (32, 23, 32, 31, WHITE); // Bottom Line
    display.drawLine (17, 15, 25, 15, WHITE); // Left Line
    display.drawLine (39, 15, 47, 15, WHITE); // Right Line              
    display.display();
  }
// End of Reticle 

void setup() { 

// Start Laser
    pinMode(inPin, INPUT);      // Laser Button
    pinMode(outPin, OUTPUT);    // Laser
// End Laser
               
      Serial.begin(9600);
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)  
      display.clearDisplay();      // clears the screen and buffer ** DO NOT REMOVE **                         

// PropTroniX Logo Display
static const unsigned char PROGMEM Logo2[] = {  
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x61, 0x86, 0x00, 0x01, 0x81, 0x81, 0x80,
0x02, 0x07, 0xE0, 0x40, 0x04, 0x07, 0xE0, 0x20, 0x08, 0x1C, 0x38, 0x10, 0x11, 0x7C, 0x3E, 0x88,
0x13, 0xFC, 0x3F, 0xD8, 0x3F, 0x7C, 0x3F, 0xFC, 0x27, 0x1C, 0x3C, 0xE4, 0x46, 0x08, 0x10, 0x60,
0x4E, 0x00, 0x00, 0x72, 0x47, 0x00, 0x00, 0x62, 0x47, 0xC0, 0x03, 0xE2, 0x47, 0xC0, 0x03, 0xE2,
0x47, 0xC0, 0x03, 0xC2, 0x47, 0x80, 0x03, 0xC2, 0x46, 0x00, 0x00, 0x42, 0x4E, 0x00, 0x00, 0x72,
0x46, 0x18, 0x10, 0x60, 0x27, 0x3C, 0x7C, 0xE4, 0x3F, 0xFC, 0x3F, 0xFC, 0x13, 0xFC, 0x3F, 0xC8,
0x10, 0x7C, 0x3E, 0x80, 0x08, 0x1C, 0x38, 0x10, 0x04, 0x07, 0xE0, 0x20, 0x03, 0x07, 0xE0, 0xC0,
0x00, 0x81, 0x81, 0x00, 0x00, 0x61, 0x8E, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00
};

  display.clearDisplay(); // Clear Screen
  display.drawBitmap(16, 0, Logo2, 32, 32, 1);  //Draw PropTroniX Logo and Place on Screen
  display.display(); //Disply Logo
  delay(3000); // Time Logo is Displayed

    display.clearDisplay(); //Clear the Display
    
    display.setTextSize(1); // Set Text Size
    display.setCursor(12,1); // Text Position                         
    display.setTextColor(WHITE); // Text Colour                         
    display.print("BLASTER"); // Text to Display                   


    display.setCursor(16,14);                         
    display.setTextColor(WHITE);                                  
    display.print("SCOPE");                                               

    display.setFont(&TomThumb),                           
    display.setCursor(1,29);                        
    display.print("PropTroniX");                 

    display.display();
    delay(2000);

    display.clearDisplay();

// Start of Bargraph Frame 
      display.drawLine (2, 2, 2, 30, WHITE);
      display.drawLine (8, 2, 8, 30, WHITE);   
      display.drawLine (2, 2, 8, 2, WHITE);   
      display.drawLine (2, 30, 8, 30, WHITE);
// End of Bargraph Frame 

      bargraphstate=Bargraph(bargraphstate);
      display.display();
  } 

void loop()  {

// Start Laser Button 
    stateButton = digitalRead(inPin);  
    if(stateButton == HIGH && previouslaser == LOW && millis() - time > debounce) {
    if(stateoutPin == HIGH){
    stateoutPin = LOW;       
  } else {
    stateoutPin = HIGH;       
  }
    time = millis();
  }
    digitalWrite(outPin, stateoutPin);
    previouslaser == stateButton;
// End Laser Button

    p+=a;     
    m = map(p,0,1023,0,100);      // map needle movement

// Show Needle
    xx = m;                       // 135 = zero position, 180 = just before middle, 0 = middle, 45 = max

// Picture Loop
    display.display();     
    radar(xx);  
  bool dodisplay=false; 
      if (lastmomentbargraph + BARGRAPHSPEED <millis()) {
      bargraphstate=Bargraph(bargraphstate);
      lastmomentbargraph=millis(); 
      dodisplay=true;       
  } 
      if (lastmomentdots + DOTSSPEED <millis()) {
      twindotstate=Twin_Dots(twindotstate);
      lastmomentdots=millis(); 
      dodisplay=true;   
  }      
      if (lastmomentsquares + SQUARESSPEED <millis()) {
      flashsquarestate=Flashing_Squares(flashsquarestate);
      lastmomentsquares=millis();
      dodisplay=true;        
  } 
      if (lastmomentnumbers + RANDOMNUMBERSSPEED <millis()) {
      randomnumbersstate=Random_Numbers(randomnumbersstate);
      lastmomentnumbers=millis();  
      dodisplay=true;     
  }
      if (lastmomentnumbers2 + RANDOMNUMBERSSPEED2 <millis()) {
      randomnumbers2state=Random_Numbers2(randomnumbers2state);
      lastmomentnumbers2=millis();  
      dodisplay=true;     
  }     
      if (dodisplay) display.display();
  }

// Start of Bargraph
  uint8_t Bargraph(uint8_t state) {
    if (state<26) {
      display.drawLine(4, 28-state, 6, 28-state, WHITE);  // Bar Up - Change  to BLACK for Bar Down
state++;
 //     display.drawLine(4, 28-state, 6, 28-state, WHITE);  // Un-Comment for Single Line Up
    return state;
  }
    else 
  {
      display.drawLine(4, 5+(state-28), 6, 5+(state-28), BLACK);  // Bar Up - Change  to WHITE for Bar Down
      state++;
//      display.drawLine(4, 5+(state-28), 6, 5+(state-28), WHITE);  // Un-Comment for Single Line Down

    if (state>52) state=0;
    return state;
  }
  }
// End of Bargraph

// Start of Twin_Dots
  uint8_t Twin_Dots(uint8_t state) {
    switch (state) {
    case 0:   // display
      display.fillCircle(display.width() / 2 + 21, display.height() / 2 + 12, 2, WHITE); //First Flashing Dot
      display.fillCircle(display.width() / 2 + 28, display.height() / 2 + 12, 2, BLACK); //Second Flashing Dot
      return 1;
    case 1:   // display
      display.fillCircle(display.width() / 2 + 21, display.height() / 2 + 12, 2, BLACK); //First Flashing Dot
      display.fillCircle(display.width() / 2 + 28, display.height() / 2 + 12, 2, WHITE); //Second Flashing Dot
    return 0;
  }
    return 0;
  }
// End of Twin_Dots

// Start of Flashing_Squares
  uint8_t Flashing_Squares(uint8_t state) {
    switch (state) {
    case 0:
      //Start of Set 1
      display.fillRect(56, 3, 2, 2, BLACK);  // 1
      display.fillRect(60, 3, 2, 2, WHITE);  // 2
      display.fillRect(56, 7, 2, 2, WHITE);  // 3
      display.fillRect(60, 7, 2, 2, WHITE);  // 4
      display.fillRect(56, 11, 2, 2, WHITE); // 5
      display.fillRect(60, 11, 2, 2, BLACK); // 6
      display.fillRect(56, 15, 2, 2, WHITE); // 7
      display.fillRect(60, 15, 2, 2, WHITE); // 8
    return 1;
    case 1:
      //Start of Set 2
      display.fillRect(56, 3, 2, 2, WHITE);  // 1
      display.fillRect(60, 3, 2, 2, WHITE);  // 2
      display.fillRect(56, 7, 2, 2, WHITE);  // 3
      display.fillRect(60, 7, 2, 2, BLACK);  // 4
      display.fillRect(56, 11, 2, 2, WHITE); // 5
      display.fillRect(60, 11, 2, 2, WHITE); // 6
      display.fillRect(56, 15, 2, 2, BLACK); // 7
      display.fillRect(60, 15, 2, 2, WHITE); // 8
    return 2;
    case 2:
      //Start of Set 3
      display.fillRect(56, 3, 2, 2, WHITE);  // 1
      display.fillRect(60, 3, 2, 2, BLACK);  // 2
      display.fillRect(56, 7, 2, 2, BLACK);  // 3
      display.fillRect(60, 7, 2, 2, WHITE);  // 4
      display.fillRect(56, 11, 2, 2, BLACK); // 5
      display.fillRect(60, 11, 2, 2, WHITE); // 6
      display.fillRect(56, 15, 2, 2, WHITE); // 7
      display.fillRect(60, 15, 2, 2, BLACK); // 8    
    return 3;
    case 3:
      //Start of Set 4
      display.fillRect(56, 3, 2, 2, WHITE);  // 1
      display.fillRect(60, 3, 2, 2, WHITE);  // 2
      display.fillRect(56, 7, 2, 2, BLACK);  // 3
      display.fillRect(60, 7, 2, 2, WHITE);  // 4
      display.fillRect(56, 11, 2, 2, WHITE); // 5
      display.fillRect(60, 11, 2, 2, WHITE); // 6
      display.fillRect(56, 15, 2, 2, WHITE); // 7
      display.fillRect(60, 15, 2, 2, BLACK); // 8
    return 4;
    case 4:
      //Start of Set 5
      display.fillRect(56, 3, 2, 2, BLACK);  // 1
      display.fillRect(60, 3, 2, 2, WHITE);  // 2
      display.fillRect(56, 7, 2, 2, WHITE);  // 3
      display.fillRect(60, 7, 2, 2, BLACK);  // 4
      display.fillRect(56, 11, 2, 2, WHITE); // 5
      display.fillRect(60, 11, 2, 2, BLACK); // 6
      display.fillRect(56, 15, 2, 2, BLACK); // 7
      display.fillRect(60, 15, 2, 2, WHITE); // 8
    return 5;
    case 5:
      //Start of Set 6
      display.fillRect(56, 3, 2, 2, WHITE);  // 1
      display.fillRect(60, 3, 2, 2, BLACK);  // 2
      display.fillRect(56, 7, 2, 2, WHITE);  // 3
      display.fillRect(60, 7, 2, 2, WHITE);  // 4
      display.fillRect(56, 11, 2, 2, BLACK); // 5
      display.fillRect(60, 11, 2, 2, WHITE); // 6
      display.fillRect(56, 15, 2, 2, WHITE); // 7
      display.fillRect(60, 15, 2, 2, WHITE); // 8
    return 0;
  }
    return 0;
  }
// End of Flashing_Squares

// Start of Random_Numbers
// Random_Numbers Top
  uint8_t Random_Numbers2(uint8_t state) {  
    randNumber2 = random(10, 99);                      
    display.fillRect(11, 0, 9, 6, BLACK); 
    //display.setFont(&TomThumb),                             
    display.setTextSize(1);
    display.setCursor(13,5);                          
    display.setTextColor(WHITE);                           
    display.print(randNumber2); 
  } 

// Random_Numbers Bottom
  uint8_t Random_Numbers(uint8_t state) {  
    randNumber = random(10, 99);                      
    display.fillRect(11, 26, 9, 6, BLACK); 
    display.setFont(&TomThumb),                             
    display.setTextSize(1);
    display.setCursor(13,31);                          
    display.setTextColor(WHITE);                           
    display.print(randNumber); 
  } 
// End of Random_Numbers
