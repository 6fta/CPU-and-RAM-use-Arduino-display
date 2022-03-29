#!/usr/bin/env python3

import time
import psutil
import serial

usb = serial.Serial('/dev/ttyUSB0')


while True:
    time.sleep(1)

    cpu = psutil.cpu_percent(interval=0.5)
    cpu = str(cpu)
    mem: object = psutil.virtual_memory().percent
    mem = str(mem)
    usb.write(b"#")
    usb.write(cpu.encode())
    usb.write(b"*")
    usb.write(mem.encode())
