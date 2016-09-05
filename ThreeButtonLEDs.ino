/*
  Button

 Turns on and off three LEDs, as well as a button to invert
 the current state of the lights.


 The circuit:
 * red LED attached from pin 13 to ground
 * yellow LED attached from pin 12 to ground
 * blue LED attached from pin 11 to ground
 * pushbutton attached to pin 2 from +5V
 * pushbutton attached to pin 3 from +5V
 * pushbutton attached to pin 4 from +5V
 * pushbutton attached to pin 5 from +5V
 * 10K resistor attached to pin 2 from ground
 * 10K resistor attached to pin 3 from ground
 * 10K resistor attached to pin 4 from ground
 * 10K resistor attached to pin 5 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 Based on code:
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int redPin =  13;      // the number of the LED pin
const int bluePin = 12;
const int yellowPin = 11;

// variables will change:
int buttonStateALL = 0;         // variable for reading the pushbutton status
int buttonStateRED = 0;
int buttonStateBLUE = 0;
int buttonStateYELLOW = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(redPin, OUTPUT); //red LED
  pinMode(yellowPin, OUTPUT); //yellow LED
  pinMode(bluePin, OUTPUT); //blue LED
  pinMode(2, INPUT); //all LED button
  pinMode(3, INPUT); //yellow LED button
  pinMode(4, INPUT); //blue LED button
  pinMode(5, INPUT); //red LED button
  // initialize the pushbutton pin as an input:
  // pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateALL = digitalRead(2);
  buttonStateRED = digitalRead(5);
  buttonStateBLUE = digitalRead(4);
  buttonStateYELLOW = digitalRead(3);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonStateALL == HIGH) {
    if (buttonStateRED == HIGH) {
      digitalWrite(redPin, LOW);
    } else {
      digitalWrite(redPin, HIGH);
    }

    if (buttonStateBLUE == HIGH) {
      digitalWrite(bluePin, LOW);
    } else {
      digitalWrite(bluePin, HIGH);
    }

    if (buttonStateYELLOW == HIGH) {
      digitalWrite(yellowPin, LOW);
    } else {
      digitalWrite(yellowPin, HIGH);
    }
  } else {
    digitalWrite(redPin, buttonStateRED);
    digitalWrite(bluePin, buttonStateBLUE);
    digitalWrite(yellowPin, buttonStateYELLOW); 
  }
}
