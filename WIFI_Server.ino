#include <ESP8266WiFi.h>  // ESP 8266 Wi-Fi & WebServer Library
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

int bulb = D1;

void setup() {
  // BULB Pin setting
  pinMode(bulb, OUTPUT);
  digitalWrite(bulb, LOW);

  // Serial setting
  Serial.begin(9600);
  Serial.println();

  // Wi-Fi Connection
  WiFi.begin("LUNABLANCA", "07921071");
  Serial.print("Connecting");
  //Wi-Fi 연결 동안 . 출력
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address : ");
  Serial.println(WiFi.localIP()); //Wi-Fi 주소 출력

  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("HTTP Server Started");
}

void handleOn() {
  digitalWrite(bulb, HIGH);
  server.send(200, "text/plain", "BULB ON");
}

void handleOff() {
  digitalWrite(bulb, LOW);
  server.send(200, "text/plain", "BULB OFF");
}

void loop() {
  server.handleClient();
}
