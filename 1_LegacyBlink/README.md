### LegacyBlink
This project subfolder uses the old way of setting up and writing to a GPIO pin directly through the GPIO functions, for learning purposes. As opposed to the modern way of making a GPIO descriptor struct. The reason the modern approach came into existence will be made more clear when you get to that in the next section.

### Build
```
make
```

### Load
```
sudo insmod gpio17LED.ko
```

### See Output
```
dmesg | tail
```

### Unload
```
sudo rmmod gpio17LED
```