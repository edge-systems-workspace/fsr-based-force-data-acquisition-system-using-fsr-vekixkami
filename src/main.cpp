#include <Arduino.h>   // Include core Arduino library

// Define FSR analog pin (Use A0)
#define FSR_PIN A0      // FSR (Force Sensitive Resistor) connected to analog pin A0

// Variable to store sensor reading
int fsrReading;         // Stores raw analog value from FSR (0–1023)

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message to Serial Monitor
    Serial.println("FSR Force Measurement System Initialized");
}

void loop() {

    // Read analog value from FSR
    // The value ranges from 0 (no force) to 1023 (maximum force)
    fsrReading = analogRead(FSR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("FSR Reading: ");
    Serial.println(fsrReading);

    // Apply simple threshold logic to detect applied pressure
    // Threshold value (200) can be adjusted based on calibration
    if (fsrReading > 200) {   
        Serial.println("Pressure Detected");        // Force is being applied
    } else {
        Serial.println("No Significant Pressure");  // Little or no force applied
    }

    // Add delay (500ms) for stable readings and readability
    delay(500);
}
