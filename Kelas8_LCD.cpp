#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C layar(0x27, 16, 2);

void setup()
{
  layar.init();
  layar.backlight();
}

void loop()
{
  layar.setCursor(0,0);
  layar.print("NAMA KALIAN");
  layar.setCursor(0,1);
  layar.print("TANGGAL LAHIR");
  delay(3000);
  layar.clear();
  delay(500);
}