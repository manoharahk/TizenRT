README
^^^^^^

This directory contains various device drivers -- both block and
character drivers as well as other more specialized drivers.

Contents:
  - Files in this directory
  - Subdirectories of this directory
  - Skeleton files

Files in this directory
^^^^^^^^^^^^^^^^^^^^^^^

can.c
  This is a CAN driver.  See include/tizenrt/can.h for usage information.

dev_null.c and dev_zero.c
  These files provide the standard /dev/null and /dev/zero devices.
  See include/tizenrt/fs/fs.h for functions that should be called if you
  want to register these devices (devnull_register() and
  devzero_register()).

loop.c
  Supports the standard loop device that can be used to export a
  file (or character device) as a block device.  See losetup() and
  loteardown() in include/tizenrt/fs/fs.h.

pwm.c
  Provides the "upper half" of a pulse width modulation (PWM) driver.
  The "lower half" of the PWM driver is provided by device-specific
  logic.  See include/tizenrt/pwm.h for usage information.

timer.c
  Provides the "upper half" for a generic timer driver.  See
  include/tizenrt/timer.h for more information.

rwbuffer.c
  A facility that can be use by any block driver in-order to add
  writing buffering and read-ahead buffering.

watchdog.c
  Provides the "upper half" for a generic watchdog driver.  See
  include/tizenrt/watchdog.h for more information.

Subdirectories of this directory:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

analog/
  This directory holds implementations of analog device drivers.
  This includes drivers for Analog to Digital Conversion (ADC).
  See include/tizenrt/analog/*.h for registration information.

net/
  Network interface drivers.  See also include/tizenrt/net/net.h

pipes/
  FIFO and named pipe drivers.  Standard interfaces are declared
  in include/unistd.h

power/
  battery driver interfaces.

serial/
  Front-end character drivers for chip-specific UARTs.  This provide
  some TTY-like functionality and are commonly used (but not required for)
  the TizenRT system console.  See also include/tizenrt/serial/serial.h

spi/
  SPI drivers.  See include/tizenrt/spi/spi.h

syslog/
  System logging devices. See include/syslog.h and include/tizenrt/syslog/syslog.h

Skeleton Files
^^^^^^^^^^^^^^

Skeleton files a "empty" frameworks for TizenRT drivers.  They are provided to
give you a good starting point if you want to create a new TizenRT driver.
The following skeleton files are available:

  drivers/net/skeleton.c -- Skeleton network/Ethernet drivers
  drivers/usbhost/usbhost_skeleton.c -- Skeleton USB host class driver
