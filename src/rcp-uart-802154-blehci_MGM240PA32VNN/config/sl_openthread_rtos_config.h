/***************************************************************************//**
 * @file
 * @brief OpenThread RTOS configuration file.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
//
// <h>  Priority Configuration for OpenThread RTOS Stack Task
// <o SL_OPENTHREAD_RTOS_STACK_TASK_PRIORITY> OpenThread stack task priority
// <i> Default: 24 (CMSIS-RTOS2 osPriorityNormal)
// <i> Defines OpenThread stack task priority. This must be a valid priority value
// <i> from CMSIS-RTOS2 osPriority_t definition.
#define SL_OPENTHREAD_RTOS_STACK_TASK_PRIORITY (24)

// </h>
// <h>  Priority Configuration for OpenThread App Task
// <o SL_OPENTHREAD_RTOS_APP_TASK_PRIORITY> OpenThread task priority
// <i> Default: 23 (CMSIS-RTOS2 osPriorityBelowNormal7)
// <i> Defines OpenThread App task priority. This must be a valid priority value
// <i> from CMSIS-RTOS2 osPriority_t definition.
#define SL_OPENTHREAD_RTOS_APP_TASK_PRIORITY (23)

// </h>
// <h>  Priority Configuration for OpenThread RTOS Stack Task
// <o SL_OPENTHREAD_RTOS_CLI_TASK_PRIORITY> OpenThread CLI task prority
// <i> Default: 16 (CMSIS-RTOS2 osPriorityBelowNormal)
// <i> Defines OpenThread CLI task priority. This must be a valid priority value
// <i> from CMSIS-RTOS2 osPriority_t definition.
#define SL_OPENTHREAD_RTOS_CLI_TASK_PRIORITY (16)

// <o SL_OPENTHREAD_STACK_TASK_MEM_SIZE> OpenThread stack task stack size in bytes <1000-20000>
// <i> Default: 4608
// <i> Defines the stack size of the OpenThread RTOS stack task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_OPENTHREAD_STACK_TASK_MEM_SIZE 4608

// <o SL_OPENTHREAD_APP_TASK_MEM_SIZE> OpenThread app task stack size in bytes <1000-20000>
// <i> Default: 4096
// <i> Defines the stack size of the OpenThread RTOS app task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_OPENTHREAD_APP_TASK_MEM_SIZE 4608

// <o SL_OPENTHREAD_CLI_TASK_MEM_SIZE> OpenThread CLI task stack size in bytes <1000-20000>
// <i> Default: 2048
// <i> Defines the stack size of the OpenThread RTOS CLI task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_OPENTHREAD_CLI_TASK_MEM_SIZE 2048
// </h>
// <h>  Priority Configuration for OpenThread RTOS Stack Task
// <o SL_OPENTHREAD_RTOS_CLI_TASK_PRIORITY> OpenThread CLI task prority
// <i> Default: 16 (CMSIS-RTOS2 osPriorityBelowNormal)
// <i> Defines OpenThread CLI task priority. This must be a valid priority value
// <i> from CMSIS-RTOS2 osPriority_t definition.
#define SL_OPENTHREAD_RTOS_CLI_TASK_PRIORITY (16)

// <o SL_OPENTHREAD_OS_CLI_TASK_SIZE> OpenThread CLI task stack size in bytes <1000-20000>
// <i> Default: 2048
// <i> Defines the stack size of the OpenThread RTOS CLI task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_OPENTHREAD_OS_CLI_TASK_SIZE 2048

// </h>
// <h> App Task
// <i> Enable default App task
// <i> Default: On
#define SL_OPENTHREAD_ENABLE_APP_TASK  (1)

// </h>
// <h> CLI Task
// <i> Enable CLI task
// <i> Default: On
#define SL_OPENTHREAD_ENABLE_CLI_TASK (1)

// </h>
// <<< end of configuration section >>>
