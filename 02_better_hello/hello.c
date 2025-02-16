#include <linux/module.h>
#include <linux/init.h>


/*
*   insmod: It's the command to insert the
*           loadable kernel module to the
*           kernel.
*
*           Usage:
*           insmod ./<Module_name>.ko
*
*   rmmod:  It's the command to remove the
*           loadable kernel module from the
*           kernel.
*           
*           Usage:
*           rmmod ./<Module_name>.ko
*   
*   modinfo:    It's the command to see the
*               description of the kernel module.
*
*           Usage:
*           modinfo <Module_name>.ko
*
*   lsmod:  It's the command to see all the loaded
*           module of the linux kernel.
*
*           Usage:
*           lsmod
*
*   modprobe:   It's the command to load module with
*               all its dependencies. For using modprobe
*               kernel module need to be present in 
*               /lib/modules path so our custom build
*               kernel module on different path cannot
*               use modprobe.
*           
*           Usage:
*           modprobe <Module_name>
*/

/*
*   There are two imp. events for linux driver
*   The loading of driver on kernel and unloading
*   of driver from kernel.
*/

/*
*   Function to use when this is
*   module is loaded to the kernel.
*   __init-> It's a macro which does nothing
*               but only increase the readibility
*               of kernel module.
*           We just have to search for this macro
*           to see what are the modules which execute
*           at the starting of the driver.
*           This is helpful when module is very big.
*/
static int
__init my_init(void){


    /*
    *   We don't use printf for linux driver
    *   because printf writes to standard IO
    *   and there is no standard IO for kernel
    *   There is only kernel's log. Kernel's log
    *   is buffer which stores whatever is written
    *   onto that buffer. It can me printed using
    *   command: dmesg
    */

    printk("hello - Hello, Kernel!\n");
    return 0;
}

/*
*   Function to execute when module
*   is unloaded from the kernel
*   __exit-> It's a macro which does nothing
*               but only increase the readibility
*               of kernel module.
*           We just have to search for this macro
*           to see what are the modules which execute
*           at the exiting of the driver.
*           This is helpful when module is very big.
*/

static void
__exit my_exit(void){
    
    printk("hello - Goodbye, kernel!\n");
}

module_init(my_init);
module_exit(my_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Junet Hossain <mail@jhossain.online");
MODULE_DESCRIPTION("A simple Hello World Linux Kernel Module");