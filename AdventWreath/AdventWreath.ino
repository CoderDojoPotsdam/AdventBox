#include <EEPROM.h>

#define BUTTON_DELAY 500
#define LED_DELAY    500
#define lmillis() ((long)millis())

const byte numLeds = 4;
const byte eepromAddress = 0;
const byte buttonPin = 8;
const byte *ledPins[numLeds] = {2,3,7,10};
byte ledsLit = 0;
long lastButtonPress, lastLedToggle;

void setup()
{
  // For debugging uncomment and do printf debugging via the serial monitor
  // with Serial.println("my comment here")
  // Serial.begin(9600);

  // Getting the number of LEDs that were lit before reset
  EEPROM.get(eepromAddress, ledsLit);
  ledsLit = max(0, min(4, ledsLit));
  
  // Set Pinmode of Button
  pinMode(buttonPin, INPUT);

  // Setting Pinmode of LED Pins
  pinMode(buttonPin, INPUT);
  for (byte i = 0; i < numLeds; i++) {
      pinMode(ledPins[i], OUTPUT);
  }

  // Turn number of LED in ledsLit
  toggleLeds();

  lastButtonPress = lmillis() + BUTTON_DELAY;
  lastLedToggle = lmillis() + LED_DELAY;
}

void loop()
{
  // Check if button was pressed
  if (lmillis() - lastButtonPress >= BUTTON_DELAY && digitalRead(buttonPin) == LOW) {
    lastButtonPress = lmillis() + BUTTON_DELAY;
    ledsLit++;
    ledsLit %= (numLeds + 1);
    EEPROM.put(eepromAddress, ledsLit);
  }

  if (lmillis() - lastLedToggle >= LED_DELAY) {
    lastLedToggle = lmillis() + LED_DELAY;
    toggleLeds();
  }
}

void toggleLeds()
{
    for (byte i = 0; i < numLeds; i++) {
        if ((i + 1) <= ledsLit) {
            digitalWrite(ledPins[i], HIGH);
        } else {
            digitalWrite(ledPins[i], LOW);
        }
    }
}