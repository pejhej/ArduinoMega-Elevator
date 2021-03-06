/*Folder responseble for sending data over an serial communication. */

// Sends one byte over and serial communication using string.
// Uses devise name in front and devide the byte witn an , as delimiter
// It writes to the serial bus.

void sendInt(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int intToSend) {
  String stringToSend = DEVICE_NAME;
  stringToSend = stringToSend + ",";
  stringToSend = stringToSend + intToSend;
  stringToSend = stringToSend + "\n";

  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  Serial.write(cString);
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
    stringToSend = stringToSend + ",";
    stringToSend = stringToSend + integers[i];
  }
  stringToSend = stringToSend + "\n";
//  int nrOfBytes = sizeof(char) * (stringToSend.length() + 1);
//  String totalString = "";
//  totalString = totalString + nrOfBytes + "," + stringToSend;


  // Make c string from arduino string by memory allocating the array.
  char* cString = (char*) malloc(sizeof(char) * (stringToSend.length() + 1));
  stringToSend.toCharArray(cString, stringToSend.length() + 1);
  Serial.write(cString);
  // Free the allocated memory.
  free(cString);
  if (debug) {
    Serial.println();
  }
}



/**
 * Sends the state of the 
 */
void intervalSendState(state stateToSend)
{
  if(timerHasPassed(waitTime))
  {
    sendInt(stateToSend);
    resetTimer();
  }
}







