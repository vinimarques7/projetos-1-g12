const int btnR = 3;
const int btnY = 5;
const int btnB = 6;

bool isPressedR = false;
bool isPressedY = false;
bool isPressedB = false;

int countR = 0;
int countY = 0;
int countB = 0;

void setup() {
  Serial.begin(9600);

  pinMode(btnR, INPUT_PULLUP);
  pinMode(btnY, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(btnR) == LOW && isPressedR == false) {
    isPressedR = true;
    countR++;
    Serial.write("Preciso sair de sala! ");
  } else if (digitalRead(btnR) == HIGH && isPressedR == true) {
    isPressedR = false;
  }

  if (digitalRead(btnY) == LOW && isPressedY == false) {
    isPressedY = true;
    countY++;
    Serial.write("Ruido excessivo! ");
  } else if (digitalRead(btnY) == HIGH && isPressedY == true) {
    isPressedY = false;
  }

  if (digitalRead(btnB) == LOW && isPressedB == false) {
    isPressedB = true;
    countB++;
    Serial.write("Tenho duvida! ");
  } else if (digitalRead(btnB) == HIGH && isPressedB == true) {
    isPressedB = false;
  }
}
