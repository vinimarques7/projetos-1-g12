#include <SoftwareSerial.h>

// botões
const int red_btn = 2; 
const int yellow_btn = 3;
const int blue_btn = 4;

// software serial bluetooth
const int bluetoothTx = 5;
const int bluetoothRx = 6;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// rgb
const int red = 9; 
const int green = 10;
const int blue =11;

int red_light = 0;
int green_light = 0;
int blue_light = 0;

// contador de clique para relatório
int red_btn_clicks = 0; 
int yellow_btn_clicks = 0;
int blue_btn_clicks = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_btn, INPUT_PULLUP);
  pinMode(yellow_btn, INPUT_PULLUP);
  pinMode(blue_btn, INPUT_PULLUP);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // Inicia a comunicação serial com o módulo Bluetooth HC-08
  bluetooth.begin(9600);
}

void loop() {
  
  int red_btn_state = digitalRead(red_btn);
  int yellow_btn_state = digitalRead(yellow_btn);
  int blue_btn_state = digitalRead(blue_btn);

  static byte last_red_btn_state = HIGH;
  static byte last_yellow_btn_state = HIGH;
  static byte last_blue_btn_state = HIGH;

  if (red_btn_state != last_red_btn_state) {
    if (red_btn_state == LOW) {
      bluetooth.print("Preciso sair de sala!");
      red_btn_clicks++;

      for (int red_light = 0; red_light <= 255; red_light++) {
        analogWrite(red, red_light); // red
        delay(15);
      }

      for (int red_light = 255; red_light >= 0; red_light--) {
        analogWrite(red, red_light); // red
        delay(15);
      }

    }
    last_red_btn_state = red_btn_state;
  }

  if (yellow_btn_state != last_yellow_btn_state) {
    if (yellow_btn_state == LOW) {
      bluetooth.print("Ruído excessivo em sala!");
      yellow_btn_clicks++;

      for (int red_light = 0; red_light <= 255; red_light++) {
        analogWrite(red, red_light); // red
        analogWrite(green, green_light); // green
        green_light++;
        delay(15);
      }

      for (int red_light = 255; red_light >= 0; red_light--) {
        analogWrite(red, red_light); // red
        analogWrite(green, green_light); // green
        green_light--;
        delay(15);
      }

    }
    last_yellow_btn_state = yellow_btn_state;
  }

  if (blue_btn_state != last_blue_btn_state) {
    if (blue_btn_state == LOW) {
      bluetooth.print("Tenho dúvida!");
      blue_btn_clicks++;

      for (int blue_light = 0; blue_light <= 255; blue_light++) {
        analogWrite(blue, blue_light); // blue
        delay(15);
      }

      for (int blue_light = 255; blue_light >= 0; blue_light--) {
        analogWrite(blue, blue_light); // red
        delay(15);
      }

    }
    last_blue_btn_state = blue_btn_state;
  }

  relatorio();
}

void relatorio() {
  // Relatório
  bluetooth.print("Preciso sair de sala: ");
  bluetooth.println(red_btn_clicks);

  bluetooth.print("Ruído excessivo: ");
  bluetooth.println(yellow_btn_clicks);

  bluetooth.print("Dúvida: ");
  bluetooth.println(blue_btn_clicks);  

  delay(1000);
}
