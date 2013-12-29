/*
 This sketch is a modified version of Project 2 (Spaceship Interface) 
 in the Arduino Starter Kit
 
 Parts required:
 1 green LED 
 2 red LEDs
 pushbutton
 10 kilohm resistor
 3 220 ohm resistors
 
 Original code created 13 September 2012 by Scott Fitzgerald
*/

// Store the voltage state of the pushbutton switch
int switchstate = 0;

void setup(){
  // declare the LED pins as outputs 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  // declare the switch pin as an input   
  pinMode(2,INPUT);
}

void loop(){

  int pinTwo = 2, pinThree = 3, pinFour = 4, pinFive = 5;
  int timeInMilliseconds = 250;
  
  // check for voltage on pin 2
  switchstate = digitalRead(pinTwo);

  // if the button is not pressed
  // blink the red LEDs  
  if (switchstate == LOW) {
    digitalWrite(pinThree, HIGH); // turn the green LED on
    digitalWrite(pinFour, LOW);  // turn the red LED off
    digitalWrite(pinFive, LOW);  // turn the red LED off
  } else {
  // switch state is high, meaning it has been pressed.  
    digitalWrite(pinThree, LOW);  // turn the green LED off
    digitalWrite(pinFour, LOW);  // turn the red LED off
    digitalWrite(pinFive, HIGH); // turn the red LED on

    delay(timeInMilliseconds);
    digitalWrite(pinFour, HIGH); // turn the red LED on
    digitalWrite(pinFive, LOW);  // turn the red LED off

    delay(timeInMilliseconds);
  }
}

