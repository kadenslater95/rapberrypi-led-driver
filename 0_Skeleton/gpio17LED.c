
// Headers for macros like MODULE_LICENSE, MODULE_AUTHOR
#include <linux/module.h>

// Headers for methods like module_init, module_exit
#include <linux/init.h>

/* Init/Exit method is called when
 * loading/unloading with modprobe or
 * insmod/rmmod
 */

/* The kernel expects these function signatures,
 * and you tell the kernel what method is init
 * via the module_init
 */ 

 // For now just output a message
static int __init led_init(void) {
    /* printk is the printf equivalent in kernel
     * space, but instead of a file like 1 for
     * stdio output, you specify a log level,
     * like info or error.
     * The equivalent of this would be
     *  - printk(KERN_INFO, "gpio17LED: Init");
     * and it will show up in dmesg, and journalctl
     */
    pr_info("gpio17LED: Init\n");

    return 0;
}

/* If you don't include an exit function the
 * kernel will think it is non-removable and
 * give an error if you try rmmod.
 */
static void __exit led_exit(void) {
    pr_info("gpio17LED: Exit\n");
}

// How the kernel knows what methods to call
module_init(led_init);
module_exit(led_exit);

/* If you don't at least include a license,
 * then the kernel assumes "PROPRIETARY",
 * and it will treat it differently
 */
MODULE_LICENSE("GPL");

/* Adding these other module metadata makes
 * output of modinfo, dmesg, lsmod, etc. more
 * clear, so it's worth always including.
 */
MODULE_AUTHOR("kadenslater95");
MODULE_DESCRIPTION("Raspberry Pi LED driver using GPIO pin 17");
