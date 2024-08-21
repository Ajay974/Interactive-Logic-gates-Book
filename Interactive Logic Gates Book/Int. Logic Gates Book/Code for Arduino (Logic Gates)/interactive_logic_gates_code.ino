const int ledPin = 11;  // Define the pin for the LED
const int button1 = 4;  // Define the pin for the first button
const int button2 = 9;  // Define the pin for the second button
  
void setup() {
  pinMode(ledPin, OUTPUT);   // Set the LED pin as an output
  pinMode(button1, INPUT);   // Set the first button pin as an input
  pinMode(button2, INPUT);   // Set the second button pin as an input
  Serial.begin(9600);        // Initialize Serial Monitor for debugging with a baud rate of 9600
}

void loop() {
  int ldr = analogRead(A4);  // Read the value from the first LDR sensor connected to analog pin A0
  int ldr1 = analogRead(A2); // Read the value from the second LDR sensor connected to analog pin A1
  int ldr2 = analogRead(A0); // Read the value from the third LDR sensor connected to analog pin A2

  // Print the LDR values to the Serial Monitor for debugging
  Serial.print("LDR values: ");
  Serial.print(ldr);
  Serial.print(", ");
  Serial.print(ldr1);
  Serial.print(", ");
  Serial.println(ldr2);

  // Conditional statements to determine which logic gate function to execute
  if (ldr <= 150 && ldr1 <= 150 && ldr2 <= 150) {
    NOT();  // Execute the NOT gate logic
  } else if (ldr <= 150 && ldr1 <= 150 && ldr2 >= 150) {
    AND();  // Execute the AND gate logic
  } else if (ldr <= 150 && ldr1 >= 150 && ldr2 >= 150) {
    NOR();  // Execute the NOR gate logic
  } else if (ldr >= 150 && ldr1 >= 150 && ldr2 >= 150) {
    XOR();  // Execute the XOR gate logic
  } else {
    digitalWrite(ledPin, LOW); // Ensure the LED is off if no condition matches
  }

  delay(100);  // Small delay to avoid rapid polling of the sensors
}

// Function to simulate NOT gate logic
void NOT() {
  Serial.println("Executing NOT gate"); // Print the gate being executed
  if (digitalRead(button1) == LOW) {    // If button1 is pressed (assuming LOW means pressed)
    digitalWrite(ledPin, HIGH);         // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);          // Otherwise, turn off the LED
  }
}

// Function to simulate AND gate logic
void AND() {
  Serial.println("Executing AND gate"); // Print the gate being executed
  if (digitalRead(button1) == HIGH && digitalRead(button2) == HIGH) { // If both button1 and button2 are pressed
    digitalWrite(ledPin, HIGH);         // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);          // Otherwise, turn off the LED
  }
}

// Function to simulate NOR gate logic
void NOR() {
  Serial.println("Executing NOR gate"); // Print the gate being executed
  if (digitalRead(button1) == LOW && digitalRead(button2) == LOW) { // If both button1 and button2 are not pressed
    digitalWrite(ledPin, HIGH);         // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);          // Otherwise, turn off the LED
  }
}

// Function to simulate XOR gate logic
void XOR() {
  Serial.println("Executing XOR gate"); // Print the gate being executed
  if (digitalRead(button1) == HIGH && digitalRead(button2) == HIGH) { // If both button1 and button2 are pressed
    digitalWrite(ledPin, LOW);          // Turn off the LED
  } else if (digitalRead(button1) == LOW && digitalRead(button2) == LOW) { // If both button1 and button2 are not pressed
    digitalWrite(ledPin, LOW);          // Turn off the LED
  } else {
    digitalWrite(ledPin, HIGH);         // Otherwise, turn on the LED
  }
}
