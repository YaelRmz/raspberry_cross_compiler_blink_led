# Prender un led con Raspberry 3B+ en C usando la biblioteca Wiring Pi

## Paquetes necesarios 
Ubuntu
```bash
sudo apt-get install build-essential
sudo apt install gcc-arm-linux-gnueabi
```

## Procedimiento
Necesitamos copiar bibliotecas y archivos compilados desde la Raspberry a Ubuntu
```bash
#pi@192.168.50.98: Es mi usuario y dirección IP en mi Raspberry

sudo scp pi@192.168.50.98:/usr/lib/libwiringPi*  /usr/lib/gcc-cross/arm-linux-gnueabi/9/
sudo scp pi@192.168.50.98:/usr/include/wiringPi* /usr/lib/gcc-cross/arm-linux-gnueabi/9/include/

sudo scp pi@192.168.50.98:/usr/lib/arm-linux-gnueabihf/libcrypt.* /usr/lib/arm-linux-gnueabi
sudo scp pi@192.168.50.98:/usr/lib/arm-linux-gnueabihf/ld-linux* /usr/lib/arm-linux-gnueabi
```

## Uso
Creamos el archivo ejecutable y lo enviamos a las Raspberry
```bash
make 
```

Dentro de la Raspberry
```bash
cd ~/Documentos/ 
./main_rb
```

### Anotaciones
Para ver la configuración de pines de la Raspberry ejecutamos (en la terminal de la Raspberry)
```bash
gpio readall
```
