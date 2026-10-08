#include "BluetoothSerial.h"

// Cek apakah Bluetooth didukung (tergantung board ESP32)
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth tidak diaktifkan! Silakan nyalakan di menu board settings.
#endif

BluetoothSerial SerialBT;

// Pin RGB LED berdasarkan perkabelan di gambar
const int redPin = 2;   // D2
const int greenPin = 4; // D4
const int bluePin = 5;  // D5

// Konfigurasi PWM ESP32
const int freq = 5000;
const int resolution = 8;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

void setup() {
  Serial.begin(115200);

  // Konfigurasi PWM Channel
  ledcSetup(redChannel, freq, resolution);
  ledcAttachPin(redPin, redChannel);
  
  ledcSetup(greenChannel, freq, resolution);
  ledcAttachPin(greenPin, greenChannel);
  
  ledcSetup(blueChannel, freq, resolution);
  ledcAttachPin(bluePin, blueChannel);

  // Inisialisasi Bluetooth Classic dengan Nama Perangkat
  SerialBT.begin("ESP32_RGB_Picker"); // Nama bluetooth yang muncul di HP
  Serial.println("Bluetooth Aktif! Silakan pairing dan sambungkan dari HP.");
}

void loop() {
  // Mengecek apakah ada data yang masuk dari HP
  if (SerialBT.available()) {
    String data = SerialBT.readStringUntil('\n');
    data.trim(); // Menghapus spasi atau karakter newline tambahan
    
    Serial.println("Data diterima: " + data);

    // Format data dari aplikasi Arduino Bluetooth Controller (biasanya mengirim format "R,G,B")
    // Contoh: 255,0,128
    int firstComma = data.indexOf(',');
    int secondComma = data.lastIndexOf(',');

    if (firstComma > 0 && secondComma > firstComma) {
      int r = data.substring(0, firstComma).toInt();
      int g = data.substring(firstComma + 1, secondComma).toInt();
      int b = data.substring(secondComma + 1).toInt();

      // Batasi nilai agar tetap di rentang 0 - 255
      r = constrain(r, 0, 255);
      g = constrain(g, 0, 255);
      b = constrain(b, 0, 255);

      // Kirim ke PWM LED RGB 
      // (Catatan: Jika pakai Common Anode, ubah jadi ledcWrite(redChannel, 255 - r); dst.)
      ledcWrite(redChannel, r);
      ledcWrite(greenChannel, g);
      ledcWrite(blueChannel, b);

      Serial.print("Red: "); Serial.print(r);
      Serial.print(" | Green: "); Serial.print(g);
      Serial.print(" | Blue: "); Serial.println(b);
    }
  }
}