#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte identificacion[6] = "00001";

void setup() 
{
  radio.begin();
  radio.openWritingPipe(identificacion);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{
  const char texto[] = "Dios es amor";
  radio.write(&texto, sizeof(texto));

  delay(1000); // Un segundo (1000 milisegundos) de espera entre envío y envío
}
