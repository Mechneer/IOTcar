#define BLYNK_TEMPLATE_ID "Your template id"
#define BLYNK_DEVICE_NAME "Your device name"
#define BLYNK_AUTH_TOKEN "Your Token"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "wİfi name";
char pass[] = "wifi password";
#define ENA 14
#define ENB 32
#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33
int x;
int y;
int hiz;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V0) {
  x = param.asInt();
}
BLYNK_WRITE(V1) {
  y = param.asInt();
  Serial.print("y");
  Serial.println(y);
  Serial.print("x");
  Serial.println(x);
  if (((x >= -2) && (x <= 2)) && (y == 10)) {
    ileri();
    Serial.println("ileri");
  }
  else if (((x >= -2) && (x <= 2)) && (y == -10)) {
    geri();
    Serial.println("geri");
  }
  else if ((x == 10) && ((y >= -1) && (y <= 1))) {
    sag();
    Serial.println("sağ");
  }
  else if ((x == -10) && ((y >= -1) && (y <= 1))) {
    sol();
    Serial.println("sol");
  }
  else if (((x >= 4) && (x <= 8)) && ((y >= 4) && (y <= 8))) {
    sag_ileri();
    Serial.println("sagileri");
  }
  else if (((x >= -8) && (x <= -4)) && ((y >= 4) && (y <= 8))) {
    sol_ileri();
    Serial.println("solileri");
  }
  else if (((x >= 4) && (x <= 8)) && ((y >= -8) && (y <= -4))) {
    sag_geri();
    Serial.println("saggeri");
  }
  else if (((x >= -8) && (x <= -4)) && ((y >= -8) && (y <= -4))) {
    sol_geri();
    Serial.println("solgeri");
  }
  else if ((x == 0) && (y == 0)) {
    fren();
    Serial.println("fren");
  }
}

BLYNK_WRITE(V2) {
  hiz = param.asInt();
}


void loop() {
  Blynk.run();
}

void ileri() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void geri() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void sol() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void sag() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void sag_ileri() {
  analogWrite(ENB, hiz + 20);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void sol_ileri() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz + 20);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void sag_geri() {
  analogWrite(ENB, hiz + 20);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void sol_geri() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz + 20);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void fren() {
  analogWrite(ENB, hiz);
  analogWrite(ENA, hiz);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
