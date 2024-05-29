const int btnR = 3;
const int btnY = 5;
const int btnB = 6;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int fadeValueR = 0;
int fadeValueG = 0;
int fadeValueB = 0;

unsigned long previousMillis = millis();
const long interval = 5;

bool isPressedR = false;
bool isPressedY = false;
bool isPressedB = false;

int corSelecionada = 0;
bool subindo = true;

int countR = 0;
int countY = 0;
int countB = 0;

void setup() {
  Serial.begin(9600);

  pinMode(btnR, INPUT_PULLUP);
  pinMode(btnY, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  if (digitalRead(btnR) == LOW && isPressedR == false) {

    isPressedR = true;
    countR++;
    Serial.write("Preciso sair de sala! ");
    corSelecionada = 1;

  } else if (digitalRead(btnR) == HIGH && isPressedR == true) {
    isPressedR = false;
  }

  if (digitalRead(btnY) == LOW && isPressedY == false) {

    isPressedY = true;
    countY++;
    Serial.write("Ruido excessivo! ");
    corSelecionada = 2;

  } else if (digitalRead(btnY) == HIGH && isPressedY == true) {
    isPressedY = false;
  }

  if (digitalRead(btnB) == LOW && isPressedB == false) {
    isPressedB = true;
    countB++;
    Serial.write("Tenho duvida! ");
    corSelecionada = 3;

  } else if (digitalRead(btnB) == HIGH && isPressedB == true) {
    isPressedB = false;
  }

  if (corSelecionada == 0) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

  } else if (corSelecionada == 1) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if ((fadeValueR <= 255) && subindo == true) {
        analogWrite(redPin, fadeValueR);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        fadeValueR++;
        if (fadeValueR == 255) {
          subindo = false;
        }
      } else if (fadeValueR >= 0 && !subindo) {
        analogWrite(redPin, fadeValueR);
        analogWrite(greenPin, fadeValueG);
        analogWrite(bluePin, fadeValueB);
        fadeValueR--;
        if (fadeValueR == 0) {
          corSelecionada = 0;
          subindo = true;
        }
      }
    }
  } else if (corSelecionada == 2) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if ((fadeValueG <= 255) && subindo == true) {
        analogWrite(redPin, fadeValueR);
        analogWrite(greenPin, fadeValueG);
        analogWrite(bluePin, 0);
        fadeValueR++;
        fadeValueG++;
        if (fadeValueG == 255) {
          subindo = false;
        }
      } else if (fadeValueG >= 0 && !subindo) {
        analogWrite(redPin, fadeValueR);
        analogWrite(greenPin, fadeValueG);
        analogWrite(bluePin, 0);
        fadeValueR--;
        fadeValueG--;
        if (fadeValueG == 0) {
          corSelecionada = 0;
          subindo = true;
        }
      }
    }
  } else if (corSelecionada == 3) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if ((fadeValueB <= 255) && subindo == true) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, fadeValueB);
        fadeValueB++;
        if (fadeValueB == 255) {
          subindo = false;
        }
      } else if (fadeValueB >= 0 && !subindo) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, fadeValueB);
        fadeValueB--;
        if (fadeValueB == 0) {
          corSelecionada = 0;
          subindo = true;
        }
      }
    }
  }
}
