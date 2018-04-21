/*Folder responseble for sending data over an serial communication. */

// Sends one byte over and serial communication using string.
// Uses devise name in front and devide the byte witn an , as delimiter
// It writes to the serial bus.

void sendInt( int intToSend) {
  String stringToSend = DEVICE_NAME;
  stringToSend = stringToSend + " , ";
  stringToSend = stringToSend + intToSend;
  stringToSend = stringToSend + ", STOP";

  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  Serial2.write(cString);
  // Free the allocated memory.
  free(cString);

  if (debug) {
    Serial.println(cString);
    Serial.println();
  }
}


// Sends multiple integers over the buss line.
void sendIntegers(int integers[]) {
  String stringToSend = DEVICE_NAME;
  for (int i = 0; i <  sizeof(integers); i++) {
    stringToSend = stringToSend + " , ";
    stringToSend = stringToSend + integers[i];
  }
  stringToSend = stringToSend + ", STOP";
  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  
  Serial2.write(cString);
  // Free the allocated memory.
  free(cString);

  if (debug) {
    Serial.println(cString);
    Serial.println();
  }
}

