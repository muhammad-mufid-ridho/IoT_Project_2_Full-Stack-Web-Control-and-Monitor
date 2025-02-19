#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>  // Gunakan WiFiClientSecure untuk HTTPS

const char* ssid = "Noeriel_plus";
const char* password = "19810730";
const char* serverUrl = "https://backend-iot-project-2.onrender.com/led-status"; // HARUS HTTPS

const int ledPin = 2; // LED di GPIO2

WiFiClientSecure client; // Gunakan WiFiClientSecure untuk HTTPS

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

    client.setInsecure(); // Abaikan verifikasi SSL (penting untuk ESP8266)
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
        http.begin(client, serverUrl); // Gunakan WiFiClientSecure

        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Respon dari Server: " + response);

            if (response.indexOf("\"status\":\"ON\"") != -1) {
                digitalWrite(ledPin, LOW); // LED menyala
            } else {
                digitalWrite(ledPin, HIGH); // LED mati
            }
        } else {
            Serial.print("Gagal terhubung ke server. Kode Error: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    }
    delay(3000); // Cek status LED setiap 3 detik
}
