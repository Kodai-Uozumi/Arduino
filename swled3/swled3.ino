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
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  unsigned char a;
  for(int i = 1; i < 16; i*=2){
    while(a = digitalRead(2)){
      digitalWrite(10, i & 1);
      digitalWrite(11, i & 2);
      digitalWrite(12, i & 4);
      digitalWrite(13, i & 8);
      delay(500);
      if(i == 1){
        i = 8;
      }else{
        i /= 2;
      }
    }
    digitalWrite(10, i & 1);
    digitalWrite(11, i & 2);
    digitalWrite(12, i & 4);
    digitalWrite(13, i & 8);
    delay(500);
    }
}
