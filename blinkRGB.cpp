#define merah 13
#define hijau 12
#define biru 11


void setup()
{
  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(biru, OUTPUT);
}

void loop()
{
  digitalWrite(merah, HIGH);
  delay(1000);
  digitalWrite(merah, LOW);
  delay(1000);
  digitalWrite(hijau, HIGH);
  delay(1000);
  digitalWrite(hijau, LOW);
  delay(1000);
  digitalWrite(biru, HIGH);
  delay(1000);
  digitalWrite(biru, LOW);
}