#include<DSM501.h>

#define DSM501_PM10 3
#define DSM501_PM25 8

DSM501 dsm501(DSM501_PM10, DSM501_PM25);

void setup()
{
  Serial.begin(9600);  //for output information

  // Initialize DSM501
  dsm501.begin(MIN_WIN_SPAN);

  // wait 60s for DSM501 to warm up
  for (int i = 1; i <= 60; i++)
  {
    delay(1000); // 1s
    Serial.print(i);
    Serial.println(" s (wait 60s for DSM501 to warm up)");
  }
}

void loop()
{
  // call dsm501 to handle updates.
  dsm501.update();
  
  // get PM density of particles over 1.0 μm
  Serial.print("PM10: ");
  Serial.print(dsm501.getParticleWeight(0));
  Serial.print(" ug/m3");
  
  // get PM density of particles over 2.5 μm
  Serial.print("  PM25: ");
  Serial.print(dsm501.getParticleWeight(1));
  Serial.print(" ug/m3");
  
  // get PM2.5 density of particles between 1.0~2.5 μm
  Serial.print("    PM2.5: ");
  Serial.print(dsm501.getPM25());
  Serial.println(" ug/m3");
}
