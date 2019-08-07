/*
 * 01LoadDefaultBitstream
 *  
 * loading the default Bitstream
 *
 * The MIT License (MIT)
 * Copyright (C) 2019  Seeed Technology Co.,Ltd.
 */

// include the library:
#include <spartan_edge_esp32_boot.h>

// initialize the spartan_edge_esp32_boot library
spartan_edge_esp32_boot esp32Cla;

// the bitstream name which we loading
#define LOADING_DEFAULT_FIEE "/overlay/spi2gpio.bit"

// the setup routine runs once when you press reset:
void setup() {
  // initialization 
  esp32Cla.begin();
  
  // Mount SD Card
  if(!SD_MMC.begin()) {
    Serial.println("Card Mount Failed,please reboot the board");
    return;
    }
  
  // XFPGA pin Initialize
  esp32Cla.xfpgaGPIOInit();

  // loading the bitstream
  esp32Cla.xlibsSstream(LOADING_DEFAULT_FIEE);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println("run");
  delay(3000);
}