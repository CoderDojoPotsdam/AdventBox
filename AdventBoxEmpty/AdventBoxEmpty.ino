#include <EEPROM.h>

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
  
  // Pins einrichten auf INPUT und OUTPUT

  // So viele LEDs anschalten, wie in EEProm steht
}

void loop()
{
 // Buttondruck testen und LEDs anschalten
}

// Zusatz A: Kannst du auch die LEDs in zufälliger Reihenfolge aufleuchten lassen?
// Zusatz B: Kannst du auch die LEDs wie eine Kerze aufflackern lassen? Zum Beispiel mit der Bibliothek #include <SoftPWM.h>?
 