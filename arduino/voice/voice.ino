// ultrasonic & voice recog
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C bisa berbeda

#define trigPin 10
#define echoPin 11
#define lampRelayPin 13 // Terhubung ke input relay

int lampState = LOW; // Logika internal: HIGH = nyala, LOW = mati
bool objectPreviouslyDetected = false;
int lastLampState = LOW;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lampRelayPin, OUTPUT);

  // Relay aktif LOW: HIGH = relay OFF (lampu mati), LOW = relay ON (lampu nyala)
  digitalWrite(lampRelayPin, HIGH); // Awalnya lampu mati

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Siap");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lampu:");
  lcd.setCursor(0, 1);
  lcd.print("MATI");
}

void loop() {
  long duration;
  int distance;

  // Ultrasonik: kirim trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Baca dari Serial (voice control)
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "ON") {
      lampState = HIGH;
      digitalWrite(lampRelayPin, LOW); // Aktifkan relay (nyalakan lampu)
    } else if (input == "OFF") {
      lampState = LOW;
      digitalWrite(lampRelayPin, HIGH); // Matikan relay (lampu mati)
    }
  }

  // Deteksi gerakan lewat sensor ultrasonik
  if (distance > 0 && distance < 30) {
    if (!objectPreviouslyDetected) {
      lampState = !lampState;
      digitalWrite(lampRelayPin, lampState == HIGH ? LOW : HIGH); // Aktif LOW
      objectPreviouslyDetected = true;
      delay(500); // Debounce
    }
  } else {
    objectPreviouslyDetected = false;
  }

  // Tampilkan di LCD jika status berubah
  if (lampState != lastLampState) {
    lcd.setCursor(0, 1);
    lcd.print("                "); // Clear baris
    lcd.setCursor(0, 1);
    lcd.print(lampState == HIGH ? "NYALA" : "MATI");
    lastLampState = lampState;
  }

  delay(100);
}
