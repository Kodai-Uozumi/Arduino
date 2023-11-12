/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  unsigned char a;
  for(int i = 2; i <= 5; i++){
    while(a = digitalRead(i)){
      analogWrite(10, 63.75 * (i - 1));
      analogWrite(11, 63.75 * (i - 1));
      digitalWrite(12, 1);
      digitalWrite(13, 1);
      delay(2.5 * (i - 1));
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      delay(10 - (2.5 * (i - 1)));
    }
  }
  analogWrite(10, 0);
  analogWrite(11, 0);
  analogWrite(12, 0);
  analogWrite(13, 0);
}
