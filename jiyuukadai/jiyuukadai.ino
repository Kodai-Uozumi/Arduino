/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include <LiquidCrystal.h>
#include "pitches.h"
const int rs = 6, en = 7, d4 = 15, d5 = 16, d6 = 17, d7 = 18;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody2[] = {
  NOTE_E4, NOTE_D4, NOTE_C4, 0, NOTE_E4, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4
};
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
int noteDurations2 = 4;
void setup() {
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Music");
  lcd.setCursor(0,1);
  lcd.print("Player!!");
  delay(3000);
}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Music Select");
  lcd.setCursor(0, 1);
  lcd.print("1 or 2");
  delay(1000);
  digitalWrite(12, digitalRead(4));
  digitalWrite(13, digitalRead(5));
  if(digitalRead(4)){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Music Play");
    lcd.setCursor(0, 1);
    lcd.print("NO.1");
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration1 = 1000 / noteDurations1[thisNote];
      tone(8, melody1[thisNote], noteDuration1);
      int pauseBetweenNotes1 = noteDuration1 * 1.30;
      delay(pauseBetweenNotes1);
      noTone(8);
    }
  }else if(digitalRead(5)){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Music Play");
    lcd.setCursor(0, 1);
    lcd.print("NO.2");
    for (int thisNote = 0; thisNote < 15; thisNote++) {
      int noteDuration2 = 1000 / noteDurations2;
      tone(8, melody2[thisNote], noteDuration2);
      int pauseBetweenNotes2 = noteDuration2 * 2.5;
      delay(pauseBetweenNotes2);
      noTone(8);
      }
  }
}
