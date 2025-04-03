#include <SoftwareSerial.h>
#include <Deneyap_BasincOlcer.h>
#include <Deneyap_6EksenAtaletselOlcumBirimi.h>     
#include <Deneyap_GPSveGLONASSkonumBelirleyici.h> 

LSM6DSM AccGyro;                                                                                 
AtmosphericPressure BaroSensor;
GPS GPS;                       
            
void setup() {
  
   Serial.begin(57600);
  
   Serial.println("");
   Serial.println("XBee gonderici baslatildi(XBee transmitter started)...");

   AccGyro.begin(0x6B);  
   BaroSensor.begin(0x76);
   GPS.begin(0x2F);

}

void loop() {
  
    neopixelWrite(RGBLED, 0, 0, 0);
  
    GPS.readGPS(RMC);
    
    int day = GPS.readDay();
    int month = GPS.readMonth();
    int year = GPS.readYear();

    int hour = GPS.readHour();
    int minute = GPS.readMinute();
    int second = GPS.readSecond();
    
    float lat = GPS.readLocationLat();
    float lng = GPS.readLocationLng();
    
    float accelX = AccGyro.readFloatAccelX();
    float accelY = AccGyro.readFloatAccelY();
    float accelZ = AccGyro.readFloatAccelZ();

    float gyroX = AccGyro.readFloatGyroX();
    float gyroY = AccGyro.readFloatGyroY();
    float gyroZ = AccGyro.readFloatGyroZ();

    float tempC = AccGyro.readTempC();
    float tempF = AccGyro.readTempF();

    float pressure = BaroSensor.getPressure();

    String telemetryMessage = 
    "Tarih (Date): " + String(day) + "/" + String(month) + "/" + String(year) + "\n" +
    "Saat (Time): " + String(hour) + ":" + String(minute) + ":" + String(second) + "\n" +
    "Konum (Location) [Lat, Lng]: " + String(lat, 7) + ", " + String(lng, 7) + "\n" +
    "Ivme (Acceleration) [X, Y, Z]: " + String(accelX) + ", " + String(accelY) + ", " + String(accelZ) + "\n" +
    "Jiro (Gyroscope) [X, Y, Z]: " + String(gyroX) + ", " + String(gyroY) + ", " + String(gyroZ) + "\n" +
    "Sicaklik (Temperature): " + String(tempC) + "C / " + String(tempF) + "F\n" +
    "Basinc (Pressure): " + String(pressure) + " hPa\n" +
    "--------------------------------------";  

    Serial.println(telemetryMessage);

    neopixelWrite(RGBLED, 64, 0, 64);
    
    delay(1000);
}