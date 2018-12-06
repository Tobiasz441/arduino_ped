int r1 = 22;
int g1 = 24;
int y1 = 26;
int r2 = 28;
int g2 = 30;
int ldr = 13;
int x, y;
volatile bool wtpb = false;
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(3), fusslampe, RISING);
  Serial.begin(9600);
  g
}

void loop() {
  x = constrain(analogRead(A0), 200, 600);
  y = map(x, 200, 600, 0, 255);
  Serial.println(analogRead(0));
  if (x > 350) {
    digitalWrite(y1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(g2, LOW);
  } else {
    digitalWrite()
  }

  if (wtpb) {
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    delay(2000);
    digitalWrite(y1, LOW);
    digitalWrite(r1, HIGH);
    delay(500);
    digitalWrite(r2, LOW);
    digitalWrite(g2, HIGH);
    delay(10000);
    g digitalWrite(g2, LOW);
    digitalWrite(r2, HIGH);
    delay(2000);
    digitalWrite(y1, HIGH);
    delay(2000);
    digitalWrite(y1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(g1, HIGH);
    wtpb = false;
  }
}

void fusslampe() { wtpb = true; }
