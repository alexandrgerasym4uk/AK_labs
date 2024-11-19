#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include "hello1.h"

MODULE_AUTHOR("Alexandr Gerasymchuk <alexandrgerasym4uk@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint myparam = 1;

module_param(myparam, uint, 0644);
MODULE_PARM_DESC(myparam, "An unsigned integer, specifies how many times to write \"Hello, world!\"");

static int __init hello2_init(void)
{
	pr_info("hello2 module loaded\n");
	print_hello(myparam);
	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
