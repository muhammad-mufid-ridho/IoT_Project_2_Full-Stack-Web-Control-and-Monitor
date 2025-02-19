#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Noeriel_plus";
const char* password = "19810730";
const char* serverUrl = "http://backend-iot-project-2.onrender.com/led-status/"; // Ganti dengan URL backend

const int ledPin = 2; // LED terhubung ke pin D4 (GPIO2)

WiFiClient client; // Tambahkan objek WiFiClient

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    WiFi.begin(ssid, password);

    Serial.print("Menghubungkan ke WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nTerhubung ke WiFi!");
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
        http.begin(client, serverUrl); // Perbaiki dengan menggunakan WiFiClient sebagai parameter pertama
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Respon dari Server: " + response);

            // Periksa status LED
            if (response.indexOf("ON") != -1) {
                digitalWrite(ledPin, LOW);
            } else {
                digitalWrite(ledPin, HIGH);
            }
        } else {
            Serial.print("Gagal terhubung ke server. Kode Error: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    }
    delay(3000); // Cek status LED setiap 3 detik
}