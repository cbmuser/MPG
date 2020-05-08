#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 20, 2);

float feedrate;
int axis  = 1;
int feed = 4
;
char axis_display = 'X';
int button1 = 0;
int button2 = 0;

void setup() 
 {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("AXIS: X         ");
  lcd.setCursor(0, 1);
  lcd.print("FEEDRATE: 1.000");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, OUTPUT);
 }

char toggle_axis(int axis)
 {
  switch (axis) {
    case 1: axis_display = 'X'; 
      break;
    case 2: axis_display = 'Y'; 
      break;
    case 3: axis_display = 'Z'; 
      break;
  }
 }

void toggle_feedrate(int feed)
 {
  switch (feed) {
    case 1: lcd.setCursor(10, 1); lcd.print("0.100"); digitalWrite(2,HIGH); digitalWrite(3,HIGH);
      break;
    case 2: lcd.setCursor(10, 1); lcd.print("0.010"); digitalWrite(2,LOW); digitalWrite(3,HIGH);
      break;
    case 3: lcd.setCursor(10, 1); lcd.print("0.001"); digitalWrite(2,HIGH); digitalWrite(3,LOW);
      break;
    case 4: lcd.setCursor(10, 1); lcd.print("1.000"); digitalWrite(2,LOW); digitalWrite(3,LOW);
      break;

   }
 }
  
void loop() 
{

  button1 = digitalRead(4);
  button2 = digitalRead(5);
  
  if (button1 == LOW)
  {
   delay (250); 
   digitalWrite(4, HIGH);
    axis++;
    if (axis == 4){ axis = 1; }

    digitalWrite(6,LOW);delay(200);
    digitalWrite(6,HIGH);delay(200);
    digitalWrite(6,LOW);delay(200);

    toggle_axis(axis);
    lcd.setCursor(6 ,0 );
    lcd.print(axis_display);
  }

  if (button2 == LOW)
  {
    digitalWrite(4, HIGH);
    delay (250);
    feed++;
    if (feed == 5) { feed = 1; }
    toggle_feedrate(feed);
 
  }

}
