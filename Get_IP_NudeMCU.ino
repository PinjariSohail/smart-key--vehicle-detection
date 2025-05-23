#include <ESP8266WiFi.h>

const char* ssid     = "vivo 1919"; // Your WiFi ssid
const char* password = "123456789"; // Your Wifi password;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Attempting to connect to SSID");
   WiFi.begin(ssid, password); //--> Activate or add or use this code if it fails to connect to wifi.
  // Attempt to connect to WiFi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    // Connect to WPA/WPA2 network. Change this line if using open or WEP  network:
    // Wait 1 seconds for connection:
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());   //You can get IP address assigned to ESP
}

void loop() {
  // put your main code here, to run repeatedly:

}
