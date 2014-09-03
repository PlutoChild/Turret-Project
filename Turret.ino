#include <Servo.h>

Servo turret;
int angle;
int pot = A0;
int potVal = 0;
int buttonR = 2;
int buttonF = 4;
int buttonL = 7;
int led = 13;
int angleSpeed = 1;
int buttonRstate = 0;
int buttonFstate = 0;
int buttonLstate = 0;

void setup() {
  turret.attach(9);
  pinMode(buttonR,INPUT);
  pinMode(buttonF,INPUT);
  pinMode(buttonL,INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  potVal = analogRead(pot);
  buttonRstate = digitalRead(buttonR);
  buttonFstate = digitalRead(buttonF);
  buttonLstate = digitalRead(buttonL);

if (buttonFstate == HIGH) {
  digitalWrite (led, HIGH);
  delay(potVal);
  digitalWrite (led, LOW);
  delay(potVal);}

if (buttonRstate == HIGH) {
  angle += angleSpeed;
  turret.write (angle);
}

if (buttonLstate == HIGH) {
  angle -= angleSpeed;
  turret.write (angle);
}

}
