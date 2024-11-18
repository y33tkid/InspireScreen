#include "Arduino.h"
#include "LiquidCrystal.h"
#include "Button.h"

// Pin Definitions
#define LCD_PIN_RS    7
#define LCD_PIN_E     6
#define LCD_PIN_DB4   2
#define LCD_PIN_DB5   3
#define LCD_PIN_DB6   4
#define LCD_PIN_DB7   5
#define PUSHBUTTON_PIN_2 8

// Global variables and defines

// Object initialization
LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_E, LCD_PIN_DB4, LCD_PIN_DB5, LCD_PIN_DB6, LCD_PIN_DB7);
Button pushButton(PUSHBUTTON_PIN_2);

// Message options
const String messages[] = {
  "You got this! ♥",
  "I believe in you!",
  "Keep going! 💪",
  "Stay strong! 💖",
  "You are amazing! 🌟",
  "Don't give up! ✨"
};
const int numMessages = sizeof(messages) / sizeof(messages[0]);

// Timer variables
const int timeout = 5000;       // Timeout duration of 5 seconds
unsigned long lastMessageTime = 0; // Timer to track message display time
bool messageDisplayed = false;  // Flag to indicate if message is currently displayed

void setup() {
  // Setup Serial for debugging
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect (only for native USB devices)

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.clear();
  
  // Test if the LCD is working by printing a simple message
  lcd.setCursor(0, 0);
  lcd.print("LCD Test...");
  delay(2000); // Wait for 2 seconds
  
  // Seed the random number generator using analog pin A0
  randomSeed(analogRead(A0));

  // Initialize the button
  pushButton.init();

  // Display an initial message
  lcd.clear(); // Clear any previous messages
  lcd.setCursor(0, 0);
  lcd.print("Press button to");
  lcd.setCursor(0, 1);
  lcd.print("see message!");

  // Print to serial monitor that the system is ready
  Serial.println("System is ready.");
  Serial.println("Press the button to see a message.");
}

void loop() {
  // Read button state
  bool buttonPressed = pushButton.read();
  if (buttonPressed && !messageDisplayed) {
    // Display a random message
    displayRandomMessage();
    messageDisplayed = true;
    lastMessageTime = millis(); // Reset the timer

    // Notify that a message is being displayed
    Serial.println("Displaying a random message.");
  }

  // If a message is displayed, check the timeout
  if (messageDisplayed && millis() - lastMessageTime >= timeout) {
    // Clear the message after the timeout
    lcd.clear();
    messageDisplayed = false;

    // Show initial prompt again
    lcd.setCursor(0, 0);
    lcd.print("Press button to");
    lcd.setCursor(0, 1);
    lcd.print("see message!");

    // Notify that the message is cleared and ready for the next press
    Serial.println("Message cleared, waiting for next press.");
  }
}

// Function to display a random message
void displayRandomMessage() {
  // Randomly pick a message from the array
  int randomIndex = random(0, numMessages);  // Random index between 0 and numMessages-1

  // Print debug message to serial monitor
  Serial.print(F("Random index: "));
  Serial.println(randomIndex); // Output the random index to the Serial Monitor
  Serial.print(F("Displaying message: "));
  Serial.println(messages[randomIndex]); // Output the message being displayed

  // Display the message on the LCD
  lcd.clear();  // Clear previous message
  lcd.setCursor(0, 0);
  lcd.print(messages[randomIndex]);
}
