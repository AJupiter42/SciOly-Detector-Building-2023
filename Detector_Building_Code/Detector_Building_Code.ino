
int redLED = 2; // Set Red LED to D2
int greenLED = 4; // Set Green LED to D4
int blueLED = 7; // Set Blue LED to D7
int fsr = 5; // Set FSR + 10K Resistor to A0
int fsrReading; // Analog Reading from FSR Voltage Divider
float fsrVoltage; // Analog Reading Converted to Voltage
float fsrMass; // Voltage Converted to Mass

void setup() {

  // Initialize LED Pins as Outputs
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

  while (analogRead(fsr) != 0) {
    
      fsrReading = analogRead(fsr);
      Serial.print("Analog Reading (0 to 1023) = ");
      Serial.println(fsrReading);
      delay(500);

      fsrVoltage = (map(fsrReading, 0, 1023, 0, 5000) / 1000.0);
      Serial.print("Voltage Reading (0 to 5V): ");
      Serial.println(fsrVoltage);
      delay(500);

      // m = 41.265V^2 + 1.9037V + 29.097

      fsrMass = 41.265 * fsrVoltage * fsrVoltage + 1.9037 * fsrVoltage + 29.097;
      Serial.print("Mass (g): ");
      Serial.println(fsrMass);

      Serial.println("------------------------------");

      delay(500);

      if (fsrVoltage > 0 && fsrVoltage <= 1.00) {

        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);

      } else if (fsrVoltage > 1.00 && fsrVoltage <= 1.25) {

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);

      } else if (fsrVoltage > 1.25 && fsrVoltage <= 3.5) {

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
      
      } else if (fsrVoltage > 3.5) {

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, HIGH);
      
      }

  }
  
  while (analogRead(fsr) == 0) {

      Serial.println("No Mass Detected");
      Serial.println("------------------------------");

      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);

      delay(500);
      
    }

} 
