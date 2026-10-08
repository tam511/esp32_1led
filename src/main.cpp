#include <Arduino.h>
#include <OneButton.h>

#define LED_PIN 2
#define BUTTON_PIN 4

OneButton btn(BUTTON_PIN, true, true);

bool ledState = false;
bool isBlinking = false;
unsigned long lastBlinkTime = 0;

void handleClick() {
  isBlinking = false;
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void handleDoubleClick() {
  isBlinking = !isBlinking;
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  btn.attachClick(handleClick);
  btn.attachDoubleClick(handleDoubleClick);
}

void loop() {
  btn.tick();

  if (isBlinking && (millis() - lastBlinkTime >= 200)) {
    lastBlinkTime = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}