/*Folder responseble for sending data over an serial communication. */

// Sends one byte over and serial communication using string.
// Uses devise name in front and devide the byte witn an , as delimiter
// It writes to the serial bus.

void sendInt(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int intToSend) {
  String stringToSend = DEVICE_NAME;
  stringToSend = stringToSend + ",";
  stringToSend = stringToSend + intToSend;
  stringToSend = stringToSend + ",STOP";

  int nrOfBytes = sizeof(char) * (stringToSend.length() + 1);
  String totalString = "";
  totalString = totalString + nrOfBytes + "," + stringToSend;

  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (totalString.length() + 1));
  totalString.toCharArray(cString, totalString.length() + 1);
  Serial.write(cString);
  delay(5);
  // Free the allocated memory.
  free(cString);

  if (debug) {
    Serial.println();
  }
}



// Sends multiple integers over the buss line.
void sendIntegers(int integers[], int arrayLength) {
  String stringToSend = DEVICE_NAME;
  for (int i = 0; i <  arrayLength; i++) {
    stringToSend = stringToSend + "," + integers[i];
  }
  stringToSend = stringToSend + ",STOP";
  int nrOfBytes = sizeof(char) * (stringToSend.length() + 1);
  String totalString = "";
  totalString = totalString + nrOfBytes + "," + stringToSend;


  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (totalString.length() + 1));
  totalString.toCharArray(cString, totalString.length() + 1);
  Serial.write(cString);
  delay(5);
  // Free the allocated memory.
  free(cString);
  if (debug) {
    Serial.println();
  }
}

