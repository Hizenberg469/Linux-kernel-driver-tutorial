
#This variable is used to specify all the object file
#which will be loaded and compile as kernel module for
#usage. And the compilation for obj file from .c file
#is done automatically.

obj-m += hello.o

# M variable used here tells the "make" to look in
# current path to build bootable kernel module from
# .c files in specified current path.

# modules: It is the target that is used to build the kernel
# 			modules.
# clean: It is used to clean the build targets, compile and 
#			generated files which would be created.
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean