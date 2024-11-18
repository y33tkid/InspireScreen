# InspireScreen
This project involves using an Arduino to drive an LCD screen that displays motivational messages. The goal is to create an automated system that can inspire and encourage users by showing uplifting quotes, affirmations, or positive reminders at regular intervals.

# Encouraging Message Board - Arduino Project

## Overview

This project involves creating an encouraging message board using an **Arduino Uno**, a **16x2 LCD display**, and a **push button**. The board will display random encouraging messages like "You got this! ♥", "I believe in you!", etc., each time the button is pressed. The message will display for 5 seconds before clearing the screen and waiting for the next button press.

## Components

- **Arduino Uno** (or any compatible Arduino board)
- **16x2 LCD Display** (with I2C or parallel interface)
- **Push Button**
- **10kΩ Potentiometer** (for adjusting LCD contrast)
- **Jumper wires and breadboard**

## Circuit Diagram

Follow the schematic below for wiring:

- **LCD Pins** (if using a parallel connection):
  - RS → Pin 7
  - Enable → Pin 6
  - D4 → Pin 2
  - D5 → Pin 3
  - D6 → Pin 4
  - D7 → Pin 5
- **Push Button**:
  - One leg of the button → Pin 8 (digital input)
  - Other leg → Ground (GND)

**Note:** If you are using an LCD with an I2C interface, the connections will be different, and you'll need to install the appropriate libraries for I2C communication.

## Software Requirements

Before uploading the sketch to your Arduino, ensure you have the following libraries installed:

1. **LiquidCrystal Library** (for controlling the 16x2 LCD)
   - This should come pre-installed with the Arduino IDE.
2. **Button Library** (for debouncing and reading button presses)
   - You can install this from the Library Manager in the Arduino IDE:
     - Go to **Sketch** → **Include Library** → **Manage Libraries**.
     - Search for **Button** and install it.

## Instructions

1. **Prepare the Files**:
   - Place the `Arduino` sketch and any libraries in the same folder. This will make sure all files are in sync.
   
2. **Wiring**:
   - Connect the 16x2 LCD to the Arduino as shown in the circuit diagram.
   - Use the **10kΩ potentiometer** to control the contrast of the LCD screen. Connect one end of the potentiometer to 5V, the other end to GND, and the middle pin to the V0 pin of the LCD.

3. **Upload the Sketch**:
   - Open the `Arduino` sketch in the Arduino IDE.
   - Select the correct **board** (Arduino Uno) and **port** (the one your Arduino is connected to).
   - Click on **Upload** to transfer the code to your Arduino.

4. **Adjust the LCD Contrast**:
   - If the LCD screen is blank, adjust the potentiometer slowly until you can see the text clearly. The potentiometer controls the contrast of the screen, and you should be able to see the text once it’s adjusted correctly.

5. **Operation**:
   - Press the push button, and the LCD will display a random encouraging message.
   - The message will be displayed for 5 seconds, then the screen will clear and reset to the initial message.
   - Press the button again to display a new random message.

## Troubleshooting

- **LCD Screen is Blank**:
  - If you can't see anything on the LCD screen, adjust the potentiometer until you can see the text clearly.
  - Check your wiring for loose connections.
  - If you're using an I2C LCD, make sure the address in your code matches the LCD's I2C address. You may need to run an I2C scanner script to find the correct address.

- **Button Not Responding**:
  - If the button isn’t triggering the message, ensure it is connected properly and is not bouncing. You can add a `delay()` or debounce in the button reading code if needed.
  
- **LCD Not Displaying the Message Correctly**:
  - Ensure that the correct LCD library is being used and that the wiring matches the defined pins in the code.
