#include <linux/module.h>
#include <linux/init.h>


/*
*   insmod: It's the command to insert the
*           loadable kernel module to the
*           kernel.
*
*   rmmod:  It's the command to remove the
*           loadable kernel module from the
*           kernel.
*/

/*
*   There are two imp. events for linux driver
*   The loading of driver on kernel and unloading
*   of driver from kernel.
*/

/*
*   Function to use when this is
*   module is loaded to the kernel.
*/
int
my_init(void){


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
*/

void
my_exit(void){
    
    printk("hello - Goodbye, kernel!\n");
}

module_init(my_init);
module_exit(my_exit);


MODULE_LICENSE("GPL");