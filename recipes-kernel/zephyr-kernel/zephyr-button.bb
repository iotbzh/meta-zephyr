require zephyr-kernel.inc
require zephyr-kernel-common.inc
inherit deploy

require zephyr-iotbzh.inc

ZEPHYR_SRC_DIR = "${S}/samples/basic/button"
