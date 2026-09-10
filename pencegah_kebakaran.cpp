const int pinGas = A0;
const int pinBuzzer = 9;

const int ledHijau = 6;
const int ledKuning = 4;
const int ledMerah = 2;

int batasKuning = 30; 
int batasMerah = 60;

void setup() {
  pinMode(pinGas, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int nilaiGas = analogRead(pinGas);
  Serial.print("Nilai Sensor Gas: ");
  Serial.println(nilaiGas);

  if (nilaiGas < batasKuning) {
    // Kondisi Aman
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, LOW);
    noTone(pinBuzzer);
  } 
  else if (nilaiGas >= batasKuning && nilaiGas < batasMerah) {
    // Kondisi Gas Sedikit
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledMerah, LOW);
    noTone(pinBuzzer);
  } 
  else {
    // Kondisi Gas Banyak (Bahaya)
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, HIGH);
    tone(pinBuzzer, 1000); // Buzzer berbunyi
  }

  delay(200);
}