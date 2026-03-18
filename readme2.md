## Setup Build Environment
* Run `util/env_bootstrap.sh`
* Run `brew install avr-gcc`
* Run `qmk setup`
* Run `qmk config user.keyboard=jsa/pragmatic54a`
* Run `make jsa/pragmatic54a:vial` and the firmware will be placed at ./jsa_pragmatic54a_vial.hex
* Open QMK Tool Box, select ./jsa_pragmatic54a_vial.hex, check the Auto-Flash box, and push the reset buttom on your keyboard

