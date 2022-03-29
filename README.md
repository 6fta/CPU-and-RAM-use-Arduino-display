# CPU-and-RAM-use-Arduino-display
Displays the processor and RAM usage of the linux operating system on an lcd display.

find ports in python:
  python3 -m serial.tools.list_ports 

  modify the port in the script if it is not ttyUSB0

  install python3:
 
  sudo apt install build-essential python3 python3-dev python3-venv python3-pip


  installation required dependencies in script:
  pip install psutil
  pip install pyserial
  pip install os-sys

  to run we open a terminal in the folder where the script is located
  if we give the order:
  
  python3 script.py

  
 if we are warned that we do not have permissions for ttyUSB0

 we grant temporary permissions by order:

  sudo chmod -R 777 /dev/ttyUSB0
  

  we grant permanent permissions by order: 

  sudo nano /etc/udev/rules.d/50-myusb.rules
  in which we add the following lines:

  KERNEL=="ttyUSB[0-9]*",MODE="0666"
  KERNEL=="ttyACM[0-9]*",MODE="0666"

  autostart command:

  sudo crontab -e

  in which we add at the end the following line:

   @reboot sleep 60 && python3 /the location of the script/script.py
   
   slepp 60 means it waits 60 seconds for the command to run
   
