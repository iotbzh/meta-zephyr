
python zephyrtest_virtclass_handler () {
    variant = e.data.getVar("BBEXTENDVARIANT", True)

    # ipk doesn't like underscores in pacakges names. So just use dashes
    # for PN and the image name.
    variant_dashes = variant.replace('_', '-')

    pn = e.data.getVar("PN", True) + "-" + variant_dashes
    pn_underscores = e.data.getVar("PN", True) + "-" + variant

    e.data.setVar("PN", pn)
    e.data.setVar("ZEPHYR_IMAGENAME", pn + ".elf")

    testsrc = e.data.getVar("ZEPHYR_TEST_SRCDIR", True)
    e.data.setVar("ZEPHYR_IMAGE_SRCDIR", testsrc + variant)

    # Allow to build using both foo-some_test form as well as foo-some-test
    e.data.setVar("PROVIDES", e.data.getVar("PROVIDES", True) + pn_underscores)
}

addhandler zephyrtest_virtclass_handler
zephyrtest_virtclass_handler[eventmask] = "bb.event.RecipePreFinalise"
