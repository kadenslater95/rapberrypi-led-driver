
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


/* When you want to register a timer with the kernel, it needs more than just a callback function to
 * execute when the time interval gets hit.
 * Other than configuration details, it gets inserted into a linked list of timer handlers and so needs
 * a pointer for that, etc.
 * But, you won't mess with those things. You'll just call convenience methods to set the callback function
 * and how many clock ticks to call this in, and it handles the rest magically.
 */
static struct timer_list led_timer;

// Keep a global copy of the current state of the led so we can toggle on/off during timer handler callbacks.
static bool led_on;


/* This is the function that we will register as the callback handler for our timer list entry.
 * When the designated time expires, this gets called.
 */
static void led_timer_func(struct time_list *t) {
    // Flip the state of the led
    led_on = !led_on;

    // The direct write to the GPIO pin through the kernel func, toggling the state between on/off
    gpio_set_value(led_gpio_pin, led_on);

    /* Update the expires on our timer_list entry so that it runs again 500ms later.
     * Note the new expiration time must be given in jiffies, so do a conversion and offset the current jiffies
     */
    mod_timer(&led_timer, jiffies + msecs_to_jiffies(500));
}


static int __init led_init(void) {
    pr_info("gpio17LED: Init\n");

    /* Get the return value from calling gpio setup commands, so we can return that value if
     * something goes wrong.
     */
    int gpio_result;

    /* TODO: Continue where I left off
    */
    gpio_result = gpio_request();

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
