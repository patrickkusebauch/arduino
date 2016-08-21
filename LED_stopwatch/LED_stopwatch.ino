#include <LiquidCrystal.h> 

LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);      

int minutes, seconds;

void setup()
{
  minutes = 0;
  seconds = 0;
  lcd.begin(16,2);      // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);   // set the cursor to column 0, line 0
  lcd.print("Stopky:"); //// Print a message to the LCD.
}
void loop()
{
  delay(1000);
  seconds += 1;
  if(seconds >= 60) {
    minutes += 1;
    seconds = 0; 
  }
  lcd.setCursor(0,2);   // set the cursor to column 0, line 2
  String text = String("");
  text += minutes;
  text += ":";
  if(seconds <= 9) {
    text += "0";
  }
  text += seconds;
  lcd.print(text);  //Print a message to the LCD.
}
