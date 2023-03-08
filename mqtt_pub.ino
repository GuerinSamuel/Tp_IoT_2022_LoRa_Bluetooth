#include <WiFi.h>
#include <PubSubClient.h>
#include <cJSON.h>

const char *ssid="Sam";
const char *password="mbpn6568";

const char *mqtt_server="test.mosquitto.org";
const char *mqtt_client_id="esp32mqtt-zen";
const char *mqtt_topic="srt/lesbv";
const int  mqtt_reconnect_ms_delay=5000;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  /*Wire.begin(21,22);
  SHT2x.begin();
  Serial.begin(9600); */
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi(){
  delay(10);
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("[WiFi] awaiting connection...");
  }
  Serial.println("[WiFi] connected !");
}


void mqtt_reconnect() {
  while (!client.connected()) {
    Serial.println("[MQTT] trying to open connection to server...");
    if (client.connect(mqtt_client_id)){
      Serial.println("[MQTT] connected to server !");
      // send message upon connection
      client.publish(mqtt_topic,"{\"freq\": 866000000, \"syncword\": 126, \"spreadingFactor\": 8, \"signalBandwidth\": 31250}");
    } else {
      Serial.print("[MQTT] failed to connect to server, rc=");
      Serial.print(client.state());
      Serial.println(" trying again...");
      delay(mqtt_reconnect_ms_delay);
    }
  }
}

void loop() {
  if(!client.connected()){
    mqtt_reconnect();
  }
  client.loop();
  /* if (now - lastMsg > 5000) { ... }
uint32_t start = micros();
Serial.print("Humidity(%RH): ");
Serial.print(SHT2x.GetHumidity(),1);
Serial.print("\tTemperature(C): ");
Serial.print(SHT2x.GetTemperature(),1);
uint32_t stop = micros();
Serial.print("\tRead Time: ");
Serial.println(stop - start);
delay(1000);
   */
}
