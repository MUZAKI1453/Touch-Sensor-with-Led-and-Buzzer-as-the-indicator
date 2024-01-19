const int touchSensorPin = 5;
const int greenLedPin = 8;
const int redLedPin = 7;
const int buzzerPin = 6;
int touchCount = 0;

void setup() {
  pinMode(touchSensorPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  // Inisialisasi komunikasi dengan Serial Monitor
  Serial.begin(9600);
  Serial.println("Touch Counter Started");
}

void loop() {
  int touchValue = digitalRead(touchSensorPin);

  if (touchValue == HIGH) {
    delay(50);
    if (digitalRead(touchSensorPin) == HIGH) {
      touchCount++;

      if (touchCount == 1) {
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
        digitalWrite(buzzerPin, HIGH);  // Aktifkan buzzer
        delay(500);
        digitalWrite(buzzerPin, LOW);   // Matikan buzzer
        Serial.print("Led Merah Menyala");
      } else if (touchCount == 2) {
        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
        digitalWrite(buzzerPin, LOW);  // Aktifkan buzzer
        delay(500);
        digitalWrite(buzzerPin, LOW);   // Matikan buzzer
        touchCount = 0;
        Serial.print("Led Hijau Menyala");
      }

      Serial.print(" : ");
      Serial.println(touchCount);
    }
  }
}
