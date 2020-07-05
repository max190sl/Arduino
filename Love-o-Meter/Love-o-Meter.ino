
const int sensorPin = A0;       // this is the pin where the temperature sensor (TMP36) is connected to
const float baselineTemp = 20;  // this constant is limit above which the first red LED is turned on

void setup() {
  Serial.begin(9600);   // start the serial communication (over USB) with a baud rate of 9600
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);   // set up pins 2,3, and 4 as output pins
    digitalWrite(pinNumber, LOW); // insure that they are off
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);  // read out the analog voltage from the temperature sensor
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  // convert digital value into a voltage (10 bit ADC = 1024 levels) with 5 volts as 1024
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  // convert the voltage into a temperature in degrees Celsius
  float temperature = (voltage - .5) * 100;
  Serial.print(", Degrees C: ");
  Serial.println(temperature);
  // turn on the LED as a function of temperature above the baselineTemp
  if (temperature<baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if (temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  // add a little delay not to stress the analog to digital converter (ADC)
  delay(1);
}
