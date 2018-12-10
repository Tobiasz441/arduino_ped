// Initialisierung von Variablen
int r1 = 22;
int g1 = 24;
int y1 = 26;
int r2 = 28;
int g2 = 30;
int ldr = 13;
int x, y;
volatile bool wtpb = false;
// Initialisierung der Funktionen
void fussampel() {
        // Phase 2
        digitalWrite(g1, LOW);
        digitalWrite(y1, HIGH);
        delay(2000);
        // Phase 3
        digitalWrite(y1, LOW);
        digitalWrite(r1, HIGH);
        delay(500);
        // Fussgängerampel an
        digitalWrite(r2, LOW);
        digitalWrite(g2, HIGH);
        delay(10000);
        // Fussgängerampel aus
        digitalWrite(g2, LOW);
        digitalWrite(r2, HIGH);
        delay(2000);
        // Phase 2
        digitalWrite(y1, HIGH);
        delay(2000);
        // Am ende wird wtpb auf falsch gesetzt um ein loop zu vermeiden
        wtpb = false;
}
void tag() {
        // Wenn hell funktioniert die Ampel wie sonst
        digitalWrite(y1, LOW);
        digitalWrite(r1, LOW);
        digitalWrite(g1, HIGH);
        digitalWrite(r2, HIGH);
        digitalWrite(g2, LOW);
}
void nacht() {
        // Wenn dunkel blinkt nur das gelbe licht
        digitalWrite(y1, LOW);
        delay(500);
        digitalWrite(y1, HIGH);
        delay(500);
        digitalWrite(r1, LOW);
        digitalWrite(g1, LOW);
        digitalWrite(r1, LOW);
        digitalWrite(g1, LOW);
        digitalWrite(r2, LOW);
        digitalWrite(g2, LOW);
}

void setup() {
<<<<<<< HEAD
  // Initialisierung des Interrupts und Serial Monitors
  attachInterrupt(digitalPinToInterrupt(3), fusslampe, RISING);
  Serial.begin(9600);
}

void loop() {
  x = constrain(analogRead(A0), 200, 600);
  Serial.println(analogRead(0));
  // Wenn hell funktioniert die Ampel wie sonst
  if (x > 350) {
    digitalWrite(y1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(g2, LOW);
  } else {
    // Wenn dunkel blinkt nur das geble Licht
    digitalWrite(y1, LOW);
    delay(500);
    digitalWrite(y1, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(g1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(g1, LOW);
  }
  // Wenn wtpb = richtig wird dieser Code ausgeführt
  if (wtpb) {
    // Phase 2
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    delay(2000);
    // Phase 3
    digitalWrite(y1, LOW);
    digitalWrite(r1, HIGH);
    delay(500);
    // Fussgängerampel an
    digitalWrite(r2, LOW);
    digitalWrite(g2, HIGH);
    delay(10000);
    // Fussgängerampel aus
    digitalWrite(g2, LOW);
    digitalWrite(r2, HIGH);
    delay(2000);
    // Phase 2
    digitalWrite(y1, HIGH);
    // Am ende wird wtpb auf falsch gesetzt um ein loop zu vermeiden
    wtpb = false;
  }
}
// Interrupt, wenn Button gedrückt setze wtpb auf true
void fusslampe() { wtpb = true; }
=======
        // Initialisierung des Interrupts und Serial Monitors
        attachInterrupt(digitalPinToInterrupt(3), fusslampe, RISING);
        Serial.begin(9600);
}

void loop() {
        x = constrain(analogRead(A0), 200, 600);
        Serial.println(analogRead(0));

        if (x > 250) {
                tag();
        } else {
                nacht();
        }
        // Wenn wtpb = richtig wird dieser Code ausgeführt
        if (wtpb) {
                fussampel();
        }
}
// Interrupt, wenn Button gedrückt setze wtpb auf true
void fusslampe() {
        wtpb = true;
}
>>>>>>> 0511f078b633d80a8eafad88b014c328c00d82d7
