#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("LUNABLANCA", "07921071");  //WIFI 이름, 비번

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
}

void loop() {
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}
