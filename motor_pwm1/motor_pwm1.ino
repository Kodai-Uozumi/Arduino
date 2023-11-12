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
int PIN_Vref = 6;
int PIN_IN1 = 7;
int PIN_IN2 = 8;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i <= 255; i += 127){
    if(i == 0){
      digitalWrite(PIN_IN1, 0);
      digitalWrite(PIN_IN2, 0);
    }else{
      digitalWrite(PIN_IN1, 0);
      digitalWrite(PIN_IN2, 1);
    }
    analogWrite(PIN_Vref, i);   // turn the LED on (HIGH is the voltage level)
    delay(2000);                       // wait for a second
  }
  for(int j = 0; j <= 255; j += 127){
    if(j == 0){
      digitalWrite(PIN_IN1, 0);
      digitalWrite(PIN_IN2, 0);
    }else{
      digitalWrite(PIN_IN1, 1);
      digitalWrite(PIN_IN2, 0);
    }
    analogWrite(PIN_Vref, j);   // turn the LED on (HIGH is the voltage level)
    delay(2000);                       // wait for a second
  }
}
