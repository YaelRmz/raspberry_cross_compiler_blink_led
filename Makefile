all:
	arm-linux-gnueabi-gcc -o main_rb main.c -lwiringPi
	scp main_rb pi@192.168.50.98:/home/pi/Documents 
