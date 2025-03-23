#include <ESP8266WiFi.h>

const char* ssid = "vivo 1919";                        
const char* password = "12345678"; 

const char * host = "192.168.214.247";        

const int httpPort = 80;

const char* Commands;                                           

int button = 5;                             
bool btn_press = true;                      
int con = 0;                                

void setup() {

  pinMode(button, INPUT_PULLUP);            
  Serial.begin(115200);                     


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Successfully Connecting");  
  Serial.println("Status : Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("-------------------------------------");
  Serial.println("");
}

void loop() {

  
  if (digitalRead(button) == LOW) {
    Serial.println("Client-------------------------------");
    Serial.print("Send Command = ");
    if (btn_press == true){
      if (con >= 2) {
        con=0;
      }
      con++;

      switch (con){
        case 2:
          Commands="buzzer_On";
          Serial.println(Commands);
          send_commands();
          break;
      }
      
      btn_press = false;
    }
  }
  else {
    btn_press = true;
  }
  delay(100);
}


void send_commands(){
  Serial.println("Sending command...");
  Serial.println("Don't press the button for now...");
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(host);


  WiFiClient client;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }

  
  Serial.print("Requesting URL : ");
  Serial.println(Commands);


  client.print(String("GET ") + Commands + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: Close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {      
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  Serial.print("Server Reply = "); 
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println("Now you can press the button ...");
  Serial.println("-------------------------------------");
  Serial.println("");
}
