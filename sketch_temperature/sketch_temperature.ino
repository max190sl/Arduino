float temp;
int tempPin = 0;

void setup() {
  Serial.begin(9600); // Setting ut the UART communication
}

void loop() {
  temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   //temp = temp * 0.156;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
   delay(1000); // update sensor reading each one second
}