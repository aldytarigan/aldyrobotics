#define merah 2
#define biru 4
#define hijau 7
#define buzzer 8

void setup()
{
  pinMode(merah, OUTPUT);
  pinMode(biru, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  // INI PERINTAH MENYALAKAN LED
  digitalWrite(merah, HIGH);
  digitalWrite(biru, HIGH);
  digitalWrite(hijau, HIGH);
  
  // BUZZER
  tone(buzzer, 262, 1000);
  delay(1000);
  tone(buzzer, 294, 1000);
  delay(1000);
  tone(buzzer, 330, 1000);
  delay(1000);
  
  // INI PERINTAH MEMATIKAN LED
  digitalWrite(hijau, LOW);
  digitalWrite(biru, LOW);
  digitalWrite(merah, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}