IOT_BRANCH="renesas"

SRC_URI = "git://git@github.com/iotbzh/zephyr.git;protocol=ssh;branch=${IOT_BRANCH};name=default \
           git://github.com/zephyrproject-rtos/cmsis.git;protocol=https;destsuffix=git/modules/cmsis;name=cmsis \
          file://0001-cmake-add-yocto-toolchain.patch \
        "

SRCREV_default = "${AUTOREV}"

ZEPHYR_BASE = "${S}"
OECMAKE_SOURCEPATH = "${ZEPHYR_SRC_DIR}"


do_deploy () {
    install -D ${B}/zephyr/${ZEPHYR_MAKE_OUTPUT} ${DEPLOYDIR}/${PN}.elf
    install -D ${B}/zephyr/zephyr.bin  ${DEPLOYDIR}/${PN}.bin
}

addtask deploy after do_compile
do_install[noexec] = "1"
