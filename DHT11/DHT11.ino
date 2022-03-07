#include <DHT.h>
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  double h = dht.readHumidity();
  double t = dht.readTemperature();

  Serial.print("습도 : "); //'시리얼 플로터' 사용을 위해 주석
  Serial.print(h);              // 습도 값 출력

  Serial.print(" | 온도 : "); //'시리얼 플로터' 사용을 위해 주석
  Serial.print(t);              // 온도 값 출력
  delay(1000);
}
