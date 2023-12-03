#makefile for XR17v35x PCIe UARTs for Linux 2.6.32 and newer
# KERNEL_SRC = /lib/modules/`uname -r`/build
KERNEL_SRC = /opt/tdx-xwayland/6.4.0/sysroots/cortexa72-cortexa53-tdx-linux/lib/modules/5.15.129-6.4.0-devel+git.67c3153d20ff/build/

all: build

obj-m += xr17v35x.o

xrpci-objs :=	xr17v35x.o

EXTRA_CFLAGS +=  -DDEBUG=1

# $(MAKE) -C $(KERNEL_SRC) SUBDIRS=$(PWD) modules
build:
	make -C $(KERNEL_SRC) M=$(PWD) modules


install:
# cp xr17v35x.ko /lib/modules/$(shell uname -r)/kernel/drivers/char
	cp xr17v35x.ko /opt/tdx-xwayland/6.4.0/sysroots/cortexa72-cortexa53-tdx-linux/lib/modules/5.15.129-6.4.0-devel+git.67c3153d20ff/kernel/drivers/char/
clean:
	rm -f *~ *.o
	rm -f *~ *.ko
