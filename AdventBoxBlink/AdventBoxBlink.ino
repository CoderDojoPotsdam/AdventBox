#define BUTTON_DELAY 250
#define lmillis() ((long)millis())

const byte numLeds = 4;
const byte buttonPin = 8;
const byte ledPin = 2;

long lastButtonPress;

void toogleLEDs() {
  // Dieses "An" wird beim Einschalten in Setup ausgeschaltet
  // d.h. nach dem Start leuchtet die Interne LED und die externe ist aus
  static bool externalLedOn = true;
  externalLedOn = !externalLedOn;
  
  digitalWrite(ledPin,      externalLedOn ? HIGH : LOW );
  digitalWrite(LED_BUILTIN, externalLedOn ? LOW  : HIGH);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(buttonPin, HIGH);

  lastButtonPress = lmillis() + BUTTON_DELAY;
  toogleLEDs();
}


void loop() {
  if (lmillis() - lastButtonPress >= BUTTON_DELAY && digitalRead(buttonPin) == LOW) {
    lastButtonPress = lmillis() + BUTTON_DELAY;
    toogleLEDs();
  }
}
