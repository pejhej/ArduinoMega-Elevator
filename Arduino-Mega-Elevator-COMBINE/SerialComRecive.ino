/**
   function that executes whenever data is received from master
   this function is registered as an event, see setup()
   When this event is called. Master wants to WRITE something to the arduino
   It is ALWAYS an command, that has to be performed.

*/

void receiveSerialEvent() {

  Serial.println("RecieveEvent(W)");
  //Check if wire is ready to be read from/incomming bits
  if (Serial2.available() > 0) {
    if (Serial2.find(DEVICE_NAME)) {
      if (debug) {
        Serial.println("This massage is for me!!");
      }

      //Byte[] to store incomming bytes on
      //TODO: Make incByte dynamic from how much is incomming
      int defaultBytes = 4;
      byte incBytes[defaultBytes];
      int cnt = 0;

      //--------------------------------------------------------------------------------------------------
      // Reads incomming command
      byte inCommand = Serial2.parseInt(); // Secound Byte represents an command.
      // Updates the commands
      recieveCommand = inCommand;
      
      //Switch command to perform the tasks given by address
      switch (recieveCommand)
      {
        //------------------------------------------------------------------
        //Command for moving the robot
        //TODO: READ INCOMMING BYTES AND STORE THEM IN DESIRED VARIABLES
        case moveRobot:
          Serial.println("*****DO MOVEROBOT RECOGNIZED*****");
          sendInt(ACK); // Send an Acknowledge
          /***Incomming values parsing****/
          //Set the new incomming positions
          newPos.zLeft = Serial2.parseInt();
          newPos.zRight = -newPos.zLeft;

          if (debug) {
            //Print the values
            Serial.print("Z left value ");
            Serial.println(newPos.zLeft);
            Serial.print("Z rigth value ");
            Serial.println(newPos.zRight);
          }
          // Main case to move robot
          mainCommand = recieveCommand;
          break;




        //-------------------------------------------------------------------------
        //Set the command for calibrating the robot.
        case doCalibrate:
          Serial.println("*****DO CALIBRATE RECOGNIZED*****");
          sendInt(ACK); // Send an Acknowledge
          mainCommand = recieveCommand;
          break;
        //-----------------


        //-------------------------------------------------------------------------
        //Set the command for calibrating the robot.
        case changeVelocity:
          Serial.println("*****CHANGE VELOCITY RECOGNIZED*****");
          sendInt(ACK); // Send an Acknowledge
          mainCommand = recieveCommand;
          break;
        //-----------------

        //-------------------------------------------------------------------------
        //Set the command for calibrating the robot.
        case changeAcceleration:
          Serial.println("*****CHANGE VELOCITY RECOGNIZED*****");
          sendInt(ACK); // Send an Acknowledge
          mainCommand = recieveCommand;
          break;
        //-----------------


        //-------------------------------------------------------------------------
        //Set the command for calibrating the robot.
        case stopRobot:
          Serial.println("*****Stop ROBOT recognized****");
          sendInt(ACK); // Send an Acknowledge
          mainCommand = recieveCommand;
          break;



          
        /**** REQUEST EVENTS ****/
        //-----------------------------------------------------------------------
        // Retrive state command recived.
        case retrieveState:
          Serial.println("*******RETRIVE STATE*******: ");
          sendInt(ACK); // Send an Acknowledge
          sendInt(inState);
          if (debug) {
            Serial.print("Response: ");
          }
          break;

          

        default:
          Serial.println("Recieve command not recognized");
          sendInt(NACK); // Send an Acknowledge

      }

      //--------------------------------------------------------------------------------------------------

      //Remove the wire buffer
      Wire.flush();


    }
  }
}

