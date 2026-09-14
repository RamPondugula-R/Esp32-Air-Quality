#define MQ135_PIN 34

void setup() {
  // Start serial communication at 115200 baud
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- MQ-135 Gas Sensor Test Initialized ---");
}

void loop() {
  // Read analog value from pin 34 (range: 0 - 4095 on ESP32)
  int rawValue = analogRead(MQ135_PIN);

  // Convert raw reading to approximate voltage (3.3V reference)
  float voltage = rawValue * (3.3 / 4095.0);

  // Print values to Serial Monitor
  Serial.print("Raw ADC: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Status: ");

  if (rawValue < 120) {
    Serial.println("Clean Air");
  } else if (rawValue < 300) {
    Serial.println("Light Gas Detected");
  } else {
    Serial.println("High Gas Concentration Detected!");
  }

  delay(1000); // Wait 2 seconds before next reading
}
