#include<string.h>
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 12;
const int IN4 = 13;
const int L = 9;
const int R = 10;

const int Kp = 150;  
const int Kd = 10;
const int Ki = 0;

const int base_speed = 50;

int error = 0, prev_error = 0;
int weight[5] = {-2, -1, 0, 1, 2};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(i + 2, INPUT);
  }
  for (int i = 7; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
  delay(5000);
}

  



void loop() {

  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);

  error = 0; // ✅ Reset error each loop

  for (int i = 0; i < 5; i++) {
    error += weight[i] * digitalRead(i + 2);
  }

  int p = error * Kp + (error-prev_error) * Kd;

  analogWrite(R, constrain(base_speed + p, 0, 255));
  analogWrite(L, constrain(base_speed - p, 0, 255));

  prev_error = error;

  
}