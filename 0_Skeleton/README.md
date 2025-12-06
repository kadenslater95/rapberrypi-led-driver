From within this directory, you can run these commands to build, load, look at printed messages, unload, look at printed messages again.

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