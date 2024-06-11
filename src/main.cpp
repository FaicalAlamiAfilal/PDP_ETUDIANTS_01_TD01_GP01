

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 33 

#define DHTTYPE    DHT11    
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  // Initialise le capteur.
  dht.begin();
    // Afficher la température avec un peu de formatage
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("capteur température:erreur de lecture"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Afficher l'humidité relative avec un peu de formatage
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("capteur humidité:erreur de lecture"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
    // Effectuer une mesure toutes les 5s(deepsleep)
  
  esp_sleep_enable_timer_wakeup(5000000);
  Serial.flush();
  esp_deep_sleep_start();
}

void loop() {
   
  
}