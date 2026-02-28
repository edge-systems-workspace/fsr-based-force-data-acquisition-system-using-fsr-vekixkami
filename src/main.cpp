#include <Arduino.h>

// Define FSR analog pin (Use A0)
#define FSR_PIN A0

// Variable to store sensor reading
int fsrReading;

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message
    Serial.println("FSR Force Measurement System Initialized");
}

void loop() {

    // Read analog value from FSR
    fsrReading = analogRead(FSR_PIN);

    // Print raw ADC value
    Serial.print("FSR Reading: ");
    Serial.println(fsrReading);

    // Apply simple threshold logic (detect pressure)
    if (fsrReading > 200) {   // Threshold can be adjusted based on calibration
        Serial.println("Pressure Detected");
    } else {
        Serial.println("No Significant Pressure");
    }

    // Add delay (500ms)
    delay(500);
}
