#include <Arduino.h>

/**
 * @file main.ino
 * @brief Embedded Force Measurement System using FSR
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program reads analog force data from a Force Sensitive Resistor (FSR)
 * connected to analog pin A0. The raw ADC value (0–1023) represents the
 * amount of pressure applied to the sensor. A simple threshold-based logic
 * is used to detect whether significant pressure is applied or not, and
 * the result is displayed in a structured format on the Serial Monitor.
 */

// Define FSR analog pin (Use A0)
#define FSR_PIN A0   ///< Analog pin connected to FSR sensor output

// Variable to store sensor reading
int fsrReading;      ///< Stores raw ADC value from FSR (0–1023)

/**
 * @brief Initializes serial communication and system message.
 *
 * This function runs once when the Arduino starts.
 * It sets up Serial communication for monitoring sensor readings.
 */
void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message
    Serial.println("FSR Force Measurement System Initialized");
}

/**
 * @brief Continuously reads FSR value and detects applied pressure.
 *
 * The loop reads the analog voltage from the FSR sensor,
 * prints the raw ADC value, and applies a threshold-based
 * logic to determine whether pressure is detected.
 */
void loop() {

    // Read analog value from FSR
    // Range: 0 (no force) to 1023 (maximum force)
    fsrReading = analogRead(FSR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("FSR Reading: ");
    Serial.println(fsrReading);

    // Apply simple threshold logic to detect applied pressure
    // Threshold can be calibrated based on sensor sensitivity
    if (fsrReading > 200) {
        Serial.println("Pressure Detected");        ///< Significant force applied
    } else {
        Serial.println("No Significant Pressure");  ///< Little or no force applied
    }

    // Add delay (500ms) for stable readings and readability
    delay(500);
}
