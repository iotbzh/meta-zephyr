
python do_flash_usb() {
    import subprocess
    return_code = subprocess.call("which dfu-util", shell=True)
    if return_code != 0:
        bb.error("ERROR: dfu_util binary not in PATH")
        sys.exit(1)

    board = d.getVar('BOARD',True)
    bb.warn("Attempting to flash board: %s" % board)

    if board == 'arduino_101_sss':
        iface = 'sensor_core'
    elif board == 'arduino_101':
        iface = 'x86_app'
    elif board == 'arduino_101_ble':
        iface = 'ble_core'
    else:
        bb.error(" Unsupported board %s" % board)
        sys.exit(2)

    image = "%s/%s.elf" % (d.getVar('DEPLOY_DIR_IMAGE', True), d.getVar('PN', True))
    statement = 'dfu-util -v -a ' + iface + ' -d 8087:0aba -D ' + image.replace('elf','bin')
    bb.note("command: %s" % statement)
    return_code = subprocess.call(statement, shell=True)
    if return_code != 0:
        bb.error("Error flashig the device [%d], reset needed?" % return_code)
    else:
        bb.warn("Success (return code %d)" % return_code)
}

addtask do_flash_usb

do_flash_usb[nostamp] = "1"
