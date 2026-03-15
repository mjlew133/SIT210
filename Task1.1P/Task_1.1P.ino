// Pins
const int buttonPin = 2;
const int porchLight = 5;
const int hallwayLight = 6;

// Timings
unsigned long porchTimer = 0;
unsigned long hallwayTimer = 0;

bool porchOn = false;
bool hallwayOn = false;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(porchLight, OUTPUT);
  pinMode(hallwayLight, OUTPUT);
}

void loop() {
  readButton();
  handleLights();
}

void readButton() {
  if (digitalRead(buttonPin) == HIGH) {
    turnPorchLightOn();
    turnHallwayLightOn();
  }
}

void turnPorchLightOn() {
  digitalWrite(porchLight, HIGH);
  porchTimer = millis();
  porchOn = true;
}

void turnHallwayLightOn() {
  digitalWrite(hallwayLight, HIGH);
  hallwayTimer = millis();
  hallwayOn = true;
}

void handleLights() {
  if (porchOn && millis() - porchTimer >= 30000) {
    digitalWrite(porchLight, LOW);
    porchOn = false;
  }

  if (hallwayOn && millis() - hallwayTimer >= 60000) {
    digitalWrite(hallwayLight, LOW);
    hallwayOn = false;
  }
}
