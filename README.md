# nRF-Connect nrf52840 Memfault Example

This is a small example application showing a Memfault integration running on an
nrf52840 development board, using the nrf-connect SDK.

## Usage

Make sure you have the Zephyr / nRF-Connect tools installed first:

https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.9.1/nrf/gs_installing.html

To build and flash this example to an nRF52840-DK (PCA10056), run the following
commands:

```bash
❯ west init .
❯ west update
❯ west build -b nrf52840dk_nrf52840 memfault_demo_app
❯ west flash
```

Open a serial terminal to access the console:

```bash
# for example, pypserial-miniterm
❯ pyserial-miniterm --raw /dev/ttyACM0 115200
```
