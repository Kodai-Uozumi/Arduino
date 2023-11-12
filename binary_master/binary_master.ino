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
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  randomSeed(analogRead(0));
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Binary Master");
  lcd.setCursor(0,1);
  lcd.print("Examination");
  delay(3000);
}
void loop() {
  for(int i = 1; i <= 3; i++){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Binary Master");
    lcd.setCursor(0, 1);
    lcd.print("Stage ( ");
    lcd.print(i);
    lcd.print(" / 3 )");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    int randNumber = random(16);
    lcd.print("How about ");
    lcd.print(randNumber);
    lcd.print("?");
    delay(3000);
    digitalWrite(10, digitalRead(2));
    digitalWrite(11, digitalRead(3));
    digitalWrite(12, digitalRead(4));
    digitalWrite(13, digitalRead(5));
    int answerNumber = digitalRead(2) * 8 + digitalRead(3) * 4 + digitalRead(4) * 2 + digitalRead(5);
    lcd.clear();
    if(randNumber == answerNumber){
      lcd.setCursor(0, 0);
      lcd.print("How about ");
      lcd.print(randNumber);
      lcd.print("?");
      lcd.setCursor(0, 1);
      lcd.print("Answer ");
      lcd.print(answerNumber);
      lcd.print(" -> OK");
      delay(2000);
      if(i == 3){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You're the");
        lcd.setCursor(0, 1);
        lcd.print("Binary Master!");
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(8, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(8);
        }
        delay(2000);
      }
    }else{
      lcd.setCursor(0, 0);
      lcd.print("How about ");
      lcd.print(randNumber);
      lcd.print("?");
      lcd.setCursor(0, 1);
      lcd.print("Answer ");
      lcd.print(answerNumber);
      lcd.print(" -> NG");
      delay(2000);
      break;
    }
  }
}
