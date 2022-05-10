/*
 * Copyright (c) 2019 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <drivers/hwinfo.h>
#include <memfault_ncs.h>

#include <memfault/components.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(app);

static void set_device_id(void) {
  uint8_t dev_id[16];
  char dev_str[33];

  (void)memset(dev_id, 0x0, sizeof(dev_id));

  /* Obtain the device id */
  ssize_t length = hwinfo_get_device_id(dev_id, sizeof(dev_id));

  /* If this fails for some reason, use all zeros instead */
  if (length <= 0) {
    length = sizeof(dev_id);
  }

  /* Render the obtained serial number in hexadecimal representation */
  for (size_t i = 0; i < length; i++) {
    sprintf(&dev_str[i * 2], "%02x", dev_id[i]);
  }

//   printk("Device ID: %s\n", dev_str);

  memfault_ncs_device_id_set(dev_str, length * 2);
}

void main(void) {
  // Set the device id based on the hardware UID
  set_device_id();

  memfault_device_info_dump();
}
