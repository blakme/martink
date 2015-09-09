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

#pragma once 

#ifdef __cplusplus
extern "C" {
#endif 

#include "config.h"

#include <inttypes.h>
#include <stddef.h>
//#include <sys/types.h>

#include <string.h>

#include <arch/soc.h>
#include "util.h"
#include "list.h"

#include "dev/block.h"
#include "dev/framebuffer.h"
#include "dev/i2c.h"
#include "dev/parallel.h"
#include "dev/serial.h"
#include "dev/tty.h"

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);
extern "C" void __cxa_pure_virtual(void);
#else 
	typedef int __guard; 
#endif

#define MODULE_INIT(func) static void __attribute__((constructor)) __##func##_ctor(void){ func(); }
#define MODULE_EXIT(func) static void __attribute__((destructor)) __##func##_ctor(void){ func(); }

#define libk_init_process(async_proc_struct_ptr, method) ASYNC_PROCESS_INIT(async_proc_struct_ptr, method)
#define libk_register_process(async_proc_struct_ptr) ASYNC_QUEUE_WORK(&ASYNC_GLOBAL_QUEUE, async_proc_struct_ptr)
#define libk_loop() while(ASYNC_RUN_PARALLEL(&ASYNC_GLOBAL_QUEUE)) { NATIVE_USLEEP(10000); }

//#include "wiinunchuck.h"