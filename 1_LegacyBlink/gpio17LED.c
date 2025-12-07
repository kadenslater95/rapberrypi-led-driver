
#include <linux/module.h>
#include <linux/init.h>


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
