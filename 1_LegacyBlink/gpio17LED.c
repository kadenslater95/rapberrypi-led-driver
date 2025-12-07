
#include <linux/module.h>
#include <linux/init.h>

// Need to register the functions for initializing, reading, writing, etc. the gpio
#include <linux/gpio.h>

// To blink the led we well make a timer function and register it with the kernel
#include <linux/timer.h>

// Jiffies gives us how many clock ticks have occured so we will use that in our timer function
#include <linux/jiffies.h>



/* This is just the default pin number we are using, but further down we make it an arg you can pass.
 * We are defaulting to pin 17 on the Raspberry PI 4 board.
 */
static unsigned int led_gpio_pin = 17;

/* module_param is a convenience function that lets you set a variable with a cmd arg when loading the
 * module.
 * e.g. in this case it would be like `sudo insmod gpio17LED.c led_gpio_pin=18` to change to 18
 * The 0644 part is a permission mask that says only sudo can set that arg.
 * The 0 means the parameter cannot be changed after the module is loaded.
 * The 644 is permission values rw-r--r--, similar to chmod on files.
 */
module_param(led_gpio_pin, uint, 0644);

/* This param description macros is just a convenience way to set a description of the param that will
 * show up if you use `modinfo` on the build kernel module (.ko file)
 */
MODULE_PARM_DESC(led_gpio_pin, "GPIO Pin number for the LED");


static int __init led_init(void) {
    pr_info("gpio17LED: Init\n");

    return 0;
}

static void __exit led_exit(void) {
    pr_info("gpio17LED: Exit\n");
}

module_init(led_init);
module_exit(led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kadenslater95");
MODULE_DESCRIPTION("Raspberry Pi LED driver using GPIO pin 17");
