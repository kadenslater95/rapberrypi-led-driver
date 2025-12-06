# obj-m is a special Make variable.
# This line tells Make that we are building a
# kernel module.
# Make will then automatically look for
# gpio17LED.c (note we don't do an intermediate
# compile, it is handled automatically)
# as the source for the kernel module to build.
# Then it will spit out the gpio17LED.ko file.
obj-m += gpio17LED.o

# This is just a normal make variable that is
# commonly named KDIR, but can be named anything.
# This keeps you from having to keep copying the
# path to the kernel build directory.
# That directory has a copy of the included
# header files (init.h, etc.) and stuff that
# is needed for the kernel module to be compiled.
# The uname -r bit is to specify that currently
# running kernel version in the path, so that
# you can run the module.
# If you were compiling for a different device
# you would change that path.
# The ?= is to not redefine it if already set,
# just standard practice to use that.
# Note: This lib modules path is Standard.
# You will be able to run it on different
# linux distros because they have the same.
KDIR ?= /lib/modules/$(shell uname -r)/build

# all is just the common name of the default
# make target. Then you can just say make
# without anything else and it will build this.
# The $(MAKE) is a way of calling the `make`
# command that keeps other args, like -C.
# We call make within this instead of gcc
# because we are actually calling the kernel's
# Makefile with these args.
# The -C is the equivalent of `cd` into that
# build directory (where the kernel Makefile
# lives) and the M= specifies that the source
# we are building is $(PWD) the current working
# directory that this Makefile is in (not the
# kernel Makefile, but this one).
# The `modules` arg is the target we want to
# build. The target defined in the kernel's
# Makefile.
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Similar to our all target, we are calling
# the kernel's Makefile, but this time our
# target is clean instead.
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
