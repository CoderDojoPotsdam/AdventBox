#include <EEPROM.h>

// Verzögerung in ms, sodass jeder Tastendruck nur einmal gezählt wird.
#define BUTTON_DELAY 250
// Verzägerung in ms, damit die LEDs nur langsam nacheinander aufleuchten.
#define LED_DELAY    0
#define lmillis() ((long)millis())

const byte numLeds = 4;
const byte eepromAddress = 0;
const byte buttonPin = 8;
const byte *ledPins[numLeds] = {2,3,7,10};
byte ledsLit = 0;
long lastButtonPress, lastLedToggle;

void setup()
{
  // Zur Fehlersuche den Kommentar "Serial.begin(9600)" auskommentieren und printf-Debugging über den seriellen Monitor durchführen
  // mit Serial.println(„mein Kommentar hier“)
  // Serial.begin(9600);

  // Ermittlung der Anzahl der LEDs, die vor dem Reset geleuchtet haben
  EEPROM.get(eepromAddress, ledsLit);
  ledsLit = max(0, min(4, ledsLit));
  
  // Pinmode des Buttons auf Eingabe festlegen und Referenzwert setzen
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);

  // Pinmode der LED-Pins auf Ausgabe festlegen
  for (byte i = 0; i < numLeds; i++) {
      pinMode(ledPins[i], OUTPUT);
  }

  // Nummer der LED in ledsLit einschalten, wie vorher aus EEProm ausgelesen
  toggleLeds();

  lastButtonPress = lmillis() + BUTTON_DELAY;
  lastLedToggle = lmillis() + LED_DELAY;
}

void loop()
{
  // Prüfen, ob Button gedrückt wurde
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
  // Zusatz A: Kannst du auch die LEDs in zufälliger Reihenfolge aufleuchten lassen?
  // Zusatz B: Kannst du auch die LEDs wie eine Kerze aufflackern lassen? Zum Beispiel mit der Bibliothek #include <SoftPWM.h>?
    for (byte i = 0; i < numLeds; i++) {
        if ((i + 1) <= ledsLit) {
            digitalWrite(ledPins[i], HIGH);
        } else {
            digitalWrite(ledPins[i], LOW);
        }
    }
}
