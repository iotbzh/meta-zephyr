DEFAULTTUNE ?= "cortexr7"

require conf/machine/include/arm/arch-armv7a.inc

TUNEVALID[cortexr7] = "Enable Cortex-R7 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexr7', ' -mcpu=cortex-r5', '', d)}"
AVAILTUNES += "cortexr7"

TUNEVALID[armv7m] = "Enable Cortex-R7 specific processor optimizations"
//TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', ' -march=armv7-m', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'armv7m', 'armv7m:', '' ,d)}"

TUNE_PKGARCH_tune-cortexr7 = "cortexr7"

ARMPKGARCH_tune-cortexr7 = "armv7m"
PACKAGE_EXTRA_ARCHS_tune-cortexr7 ="cortexr7"

TUNE_FEATURES_tune-cortexr7 = "armv7m vfp cortexr7"
PACKAGE_EXTRA_ARCHS_tune-cortexr7 = "${PACKAGE_EXTRA_ARCHS_tune-armv7at} armv7m-vfp"

TUNE_CCARGS_MFLOAT = "soft"
