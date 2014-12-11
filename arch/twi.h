/**
	This file is part of martink project.

	martink firmware project is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	martink firmware is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with martink firmware.  If not, see <http://www.gnu.org/licenses/>.

	Author: Martin K. Schröder
	Email: info@fortmax.se
	Github: https://github.com/mkschreder
*/

#include "autoconf.h"

#define I2C_READ    1
#define I2C_WRITE   0

#ifndef CONFIG_TWI0_NAME
#define CONFIG_TWI0_NAME twi0
#endif

struct twi_api {
	
}; 

// generic twi interface
#ifdef CONFIG_HAVE_TWI

#define twi0_init() PFCALL(CONFIG_TWI0_NAME, init)
#define twi0_start(addr) PFCALL(CONFIG_TWI0_NAME, start, addr) 
#define twi0_stop() PFCALL(CONFIG_TWI0_NAME, stop) 
#define twi0_rep_start(addr) PFCALL(CONFIG_TWI0_NAME, rep_start, addr)
#define twi0_start_wait(addr) PFCALL(CONFIG_TWI0_NAME, start_wait, addr)
#define twi0_write(ch) PFCALL(CONFIG_TWI0_NAME, write, ch)
#define twi0_readAck() PFCALL(CONFIG_TWI0_NAME, readAck)
#define twi0_readNak() PFCALL(CONFIG_TWI0_NAME, readNak)

/// initializes twi bus
#define i2c_init twi0_init
/// sends start condition
#define i2c_start(addr) twi0_start(addr)
/// signals stop condition
#define i2c_stop() twi0_stop()
/// signals repeated start 
#define i2c_rep_start(addr) twi0_rep_start(addr)
/// waits until device is ready before sending start
#define i2c_start_wait(addr) twi0_start_wait(addr)
/// writes a byte to the device
#define i2c_write(ch) twi0_write(ch)
/// reads and sends ack
#define i2c_readAck() twi0_readAck()
/// reads without sending an ack
#define i2c_readNak() twi0_readNak()
/// helper read method
#define i2c_read(ack)  ((ack) ? i2c_readAck() : i2c_readNak())

#endif

