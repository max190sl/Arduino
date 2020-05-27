/* This code is from the Arduino Projects Book found in the Starter Kit.
 *  More specifically, it is from chaper 3, page 37.
 *  
 *  The program shows a green LED until the push button is pressed at which points two red LEDs
 *  flashes in alternance at a quarter seconds each until the button is releassed.
 */
 
int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  // These are the digital pins (just above the word UNO).
}

void loop() {
  switchState = digitalRead(2); // Checking if the button is high or low

  if (switchState == LOW) { //the button is not pressed
    digitalWrite(3, HIGH);  // the green LED is on
    digitalWrite(4, LOW);   // the red LED is off
    digitalWrite(5, LOW);   // the other red LED is also off
  }
  else {  // The button is pressed
    digitalWrite(3, LOW);   // the green LED is off
    digitalWrite(4, LOW);   // the first LED is off
    digitalWrite(5, HIGH);  // the second LED is now on
    delay(250);   // wait for a quarter of a secong
    digitalWrite(4, HIGH);  // the frist red LED is now on
    digitalWrite(5, LOW);   // the second red LED is off
  }
} // go back to the beginning of loop
