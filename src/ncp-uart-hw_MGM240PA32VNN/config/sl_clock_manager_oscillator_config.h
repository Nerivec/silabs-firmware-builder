/***************************************************************************//**
 * @file
 * @brief Clock Manager - Oscillators configuration file.
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

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef SL_CLOCK_MANAGER_OSCILLATOR_CONFIG_H
#define SL_CLOCK_MANAGER_OSCILLATOR_CONFIG_H

// <h> Oscillators Settings

// <e SL_CLOCK_MANAGER_HFXO_EN> HFXO Settings (if High Frequency crystal is used)
// <i> Enable to configure HFXO
#ifndef SL_CLOCK_MANAGER_HFXO_EN
#define SL_CLOCK_MANAGER_HFXO_EN    1
#endif

// <o SL_CLOCK_MANAGER_HFXO_MODE> Mode
// <i>
// <HFXO_CFG_MODE_XTAL=> XTAL
// <HFXO_CFG_MODE_EXTCLK=> EXTCLK
// <HFXO_CFG_MODE_EXTCLKPKDET=> EXTCLKPKDET
// <d> HFXO_CFG_MODE_XTAL
#ifndef SL_CLOCK_MANAGER_HFXO_MODE
#define SL_CLOCK_MANAGER_HFXO_MODE    HFXO_CFG_MODE_XTAL
#endif

// <o SL_CLOCK_MANAGER_HFXO_FREQ> Frequency <38000000-40000000>
// <d> 39000000
#ifndef SL_CLOCK_MANAGER_HFXO_FREQ
#define SL_CLOCK_MANAGER_HFXO_FREQ    39000000
#endif

// <o SL_CLOCK_MANAGER_HFXO_CTUNE> CTUNE <0-255>
// <d> 140
#ifndef SL_CLOCK_MANAGER_HFXO_CTUNE
#define SL_CLOCK_MANAGER_HFXO_CTUNE    140
#endif

// <o SL_CLOCK_MANAGER_HFXO_PRECISION> Precision <0-65535>
// <d> 50
#ifndef SL_CLOCK_MANAGER_HFXO_PRECISION
#define SL_CLOCK_MANAGER_HFXO_PRECISION    50
#endif

// <e SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_EN> HFXO crystal sharing feature
// <i> Enable to configure HFXO crystal sharing leader or follower
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_EN
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_EN    0
#endif

// <e SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_EN> Crystal sharing leader
// <i> Enable to configure HFXO crystal sharing leader
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_EN
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_EN    0
#endif

// <e SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_MIN_STARTUP_DELAY_EN> Crystal sharing leader minimum startup delay
// <i> If enabled, BUFOUT does not start until timeout set in
// <i> SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_TIMEOUT_STARTUP expires.
// <i> This prevents waste of power if BUFOUT is ready too early.
// <d> 1
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_MIN_STARTUP_DELAY_EN
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_MIN_STARTUP_DELAY_EN    1
#endif

// <o SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_TIMEOUT_STARTUP> Wait duration of oscillator startup sequence
// <i>
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T42US=> T42US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T83US=> T83US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T108US=> T108US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T133US=> T133US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T158US=> T158US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T183US=> T183US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T208US=> T208US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T233US=> T233US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T258US=> T258US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T283US=> T283US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T333US=> T333US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T375US=> T375US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T417US=> T417US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T458US=> T458US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T500US=> T500US
// <HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T667US=> T667US
// <d> HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T208US
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_TIMEOUT_STARTUP
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_TIMEOUT_STARTUP    HFXO_BUFOUTCTRL_TIMEOUTSTARTUP_T208US
#endif
// </e>
// </e>

// <e SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_FOLLOWER_EN> Crystal sharing follower
// <i> Enable to configure HFXO crystal sharing follower
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_FOLLOWER_EN
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_FOLLOWER_EN    0
#endif
// </e>

// <o SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PORT> GPIO Port
// <i> Bufout request GPIO port. If SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_EN
// <i> is enabled, this port will be used to receive the BUFOUT request. If
// <i> SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_FOLLOWER_EN is enabled this port
// <i> will be used to request BUFOUT from the crystal sharing leader.
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PORT
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PORT    0
#endif

// <o SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PIN> GPIO Pin
// <i> Bufout request GPIO pin. If SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_LEADER_EN
// <i> is enabled, this pin will be used to receive the BUFOUT request. If
// <i> SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_FOLLOWER_EN is enabled this pin
// <i> will be used to request BUFOUT from the crystal sharing leader.
#ifndef SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PIN
#define SL_CLOCK_MANAGER_HFXO_CRYSTAL_SHARING_GPIO_PIN    10
#endif
// </e>
// </e>

// <e> LFXO Settings (if Low Frequency crystal is used)
// <i> Enable to configure LFXO
#ifndef SL_CLOCK_MANAGER_LFXO_EN
#define SL_CLOCK_MANAGER_LFXO_EN    1
#endif

// <o SL_CLOCK_MANAGER_LFXO_MODE> Mode
// <i>
// <LFXO_CFG_MODE_XTAL=> XTAL
// <LFXO_CFG_MODE_BUFEXTCLK=> BUFEXTCLK
// <LFXO_CFG_MODE_DIGEXTCLK=> DIGEXTCLK
// <d> LFXO_CFG_MODE_XTAL
#ifndef SL_CLOCK_MANAGER_LFXO_MODE
#define SL_CLOCK_MANAGER_LFXO_MODE    LFXO_CFG_MODE_XTAL
#endif

// <o SL_CLOCK_MANAGER_LFXO_CTUNE> CTUNE <0-127>
// <d> 63
#ifndef SL_CLOCK_MANAGER_LFXO_CTUNE
#define SL_CLOCK_MANAGER_LFXO_CTUNE    63
#endif

// <o SL_CLOCK_MANAGER_LFXO_PRECISION> LFXO precision in PPM <0-65535>
// <d> 50
#ifndef SL_CLOCK_MANAGER_LFXO_PRECISION
#define SL_CLOCK_MANAGER_LFXO_PRECISION    50
#endif

// <o SL_CLOCK_MANAGER_LFXO_TIMEOUT> Startup Timeout Delay
// <i>
// <LFXO_CFG_TIMEOUT_CYCLES2=> CYCLES2
// <LFXO_CFG_TIMEOUT_CYCLES256=> CYCLES256
// <LFXO_CFG_TIMEOUT_CYCLES1K=> CYCLES1K
// <LFXO_CFG_TIMEOUT_CYCLES2K=> CYCLES2K
// <LFXO_CFG_TIMEOUT_CYCLES4K=> CYCLES4K
// <LFXO_CFG_TIMEOUT_CYCLES8K=> CYCLES8K
// <LFXO_CFG_TIMEOUT_CYCLES16K=> CYCLES16K
// <LFXO_CFG_TIMEOUT_CYCLES32K=> CYCLES32K
// <d> LFXO_CFG_TIMEOUT_CYCLES4K
#ifndef SL_CLOCK_MANAGER_LFXO_TIMEOUT
#define SL_CLOCK_MANAGER_LFXO_TIMEOUT    LFXO_CFG_TIMEOUT_CYCLES4K
#endif
// </e>

// <h> HFRCO and DPLL Settings
// <o SL_CLOCK_MANAGER_HFRCO_BAND> Frequency Band
// <i> RC Oscillator Frequency Band
// <cmuHFRCODPLLFreq_1M0Hz=> 1 MHz
// <cmuHFRCODPLLFreq_2M0Hz=> 2 MHz
// <cmuHFRCODPLLFreq_4M0Hz=> 4 MHz
// <cmuHFRCODPLLFreq_7M0Hz=> 7 MHz
// <cmuHFRCODPLLFreq_13M0Hz=> 13 MHz
// <cmuHFRCODPLLFreq_16M0Hz=> 16 MHz
// <cmuHFRCODPLLFreq_19M0Hz=> 19 MHz
// <cmuHFRCODPLLFreq_26M0Hz=> 26 MHz
// <cmuHFRCODPLLFreq_32M0Hz=> 32 MHz
// <cmuHFRCODPLLFreq_38M0Hz=> 38 MHz
// <cmuHFRCODPLLFreq_48M0Hz=> 48 MHz
// <cmuHFRCODPLLFreq_56M0Hz=> 56 MHz
// <cmuHFRCODPLLFreq_64M0Hz=> 64 MHz
// <cmuHFRCODPLLFreq_80M0Hz=> 80 MHz
// <d> cmuHFRCODPLLFreq_80M0Hz
#ifndef SL_CLOCK_MANAGER_HFRCO_BAND
#define SL_CLOCK_MANAGER_HFRCO_BAND    cmuHFRCODPLLFreq_80M0Hz
#endif

// <e> Use DPLL
// <i> Enable to use the DPLL with HFRCO
#ifndef SL_CLOCK_MANAGER_HFRCO_DPLL_EN
#define SL_CLOCK_MANAGER_HFRCO_DPLL_EN    0
#endif

// <o SL_CLOCK_MANAGER_DPLL_FREQ> Target Frequency <1000000-80000000>
// <i> DPLL target frequency
// <d> 78000000
#ifndef SL_CLOCK_MANAGER_DPLL_FREQ
#define SL_CLOCK_MANAGER_DPLL_FREQ    78000000
#endif

// <o SL_CLOCK_MANAGER_DPLL_N> Numerator (N) <300-4095>
// <i> Value of N for output frequency calculation fout = fref * (N+1) / (M+1)
// <d> 3839
#ifndef SL_CLOCK_MANAGER_DPLL_N
#define SL_CLOCK_MANAGER_DPLL_N    3839
#endif

// <o SL_CLOCK_MANAGER_DPLL_M> Denominator (M) <0-4095>
// <i> Value of M for output frequency calculation fout = fref * (N+1) / (M+1)
// <d> 1919
#ifndef SL_CLOCK_MANAGER_DPLL_M
#define SL_CLOCK_MANAGER_DPLL_M    1919
#endif

// <o SL_CLOCK_MANAGER_DPLL_REFCLK> Reference Clock
// <i> Reference clock source for DPLL
// <CMU_DPLLREFCLKCTRL_CLKSEL_DISABLED=> DISABLED
// <CMU_DPLLREFCLKCTRL_CLKSEL_HFXO=> HFXO
// <CMU_DPLLREFCLKCTRL_CLKSEL_LFXO=> LFXO
// <d> CMU_DPLLREFCLKCTRL_CLKSEL_HFXO
#ifndef SL_CLOCK_MANAGER_DPLL_REFCLK
#define SL_CLOCK_MANAGER_DPLL_REFCLK    CMU_DPLLREFCLKCTRL_CLKSEL_HFXO
#endif

// <o SL_CLOCK_MANAGER_DPLL_EDGE> Reference Clock Edge Detect
// <i> Edge detection for reference clock
// <cmuDPLLEdgeSel_Fall=> Falling Edge
// <cmuDPLLEdgeSel_Rise=> Rising Edge
// <d> cmuDPLLEdgeSel_Fall
#ifndef SL_CLOCK_MANAGER_DPLL_EDGE
#define SL_CLOCK_MANAGER_DPLL_EDGE    cmuDPLLEdgeSel_Fall
#endif

// <o SL_CLOCK_MANAGER_DPLL_LOCKMODE> DPLL Lock Mode
// <i> Lock mode
// <cmuDPLLLockMode_Freq=> Frequency-Lock Loop
// <cmuDPLLLockMode_Phase=> Phase-Lock Loop
// <d> cmuDPLLLockMode_Freq
#ifndef SL_CLOCK_MANAGER_DPLL_LOCKMODE
#define SL_CLOCK_MANAGER_DPLL_LOCKMODE    cmuDPLLLockMode_Phase
#endif

// <q SL_CLOCK_MANAGER_DPLL_AUTORECOVER> Automatic Lock Recovery
// <d> 1
#ifndef SL_CLOCK_MANAGER_DPLL_AUTORECOVER
#define SL_CLOCK_MANAGER_DPLL_AUTORECOVER    1
#endif

// <q SL_CLOCK_MANAGER_DPLL_DITHER> Enable Dither
// <d> 0
#ifndef SL_CLOCK_MANAGER_DPLL_DITHER
#define SL_CLOCK_MANAGER_DPLL_DITHER    0
#endif
// </e>
// </h>

// <h> HFRCOEM23 Settings
// <o SL_CLOCK_MANAGER_HFRCOEM23_BAND> Frequency Band
// <i> RC Oscillator Frequency Band
// <cmuHFRCOEM23Freq_1M0Hz=> 1 MHz
// <cmuHFRCOEM23Freq_2M0Hz=> 2 MHz
// <cmuHFRCOEM23Freq_4M0Hz=> 4 MHz
// <cmuHFRCOEM23Freq_13M0Hz=> 13 MHz
// <cmuHFRCOEM23Freq_16M0Hz=> 16 MHz
// <cmuHFRCOEM23Freq_19M0Hz=> 19 MHz
// <cmuHFRCOEM23Freq_26M0Hz=> 26 MHz
// <cmuHFRCOEM23Freq_32M0Hz=> 32 MHz
// <cmuHFRCOEM23Freq_40M0Hz=> 40 MHz
// <d> cmuHFRCOEM23Freq_19M0Hz
#ifndef SL_CLOCK_MANAGER_HFRCOEM23_BAND
#define SL_CLOCK_MANAGER_HFRCOEM23_BAND    cmuHFRCOEM23Freq_19M0Hz
#endif
// </h>

// <h> LFRCO Settings
// <o SL_CLOCK_MANAGER_LFRCO_PRECISION> Precision Mode
// <i> Precision mode uses hardware to automatically re-calibrate the LFRCO
// <i> against a crystal driven by the HFXO. Hardware detects temperature
// <i> changes and initiates a re-calibration of the LFRCO as needed when
// <i> operating in EM0, EM1, or EM2. If a re-calibration is necessary and the
// <i> HFXO is not active, the precision mode hardware will automatically
// <i> enable HFXO for a short time to perform the calibration. EM4 operation is
// <i> not allowed while precision mode is enabled.
// <i> If high precision is selected on devices that do not support it, default
// <i> precision will be used.
// <cmuPrecisionDefault=> Default precision
// <cmuPrecisionHigh=> High precision
// <d> cmuPrecisionDefault
#ifndef SL_CLOCK_MANAGER_LFRCO_PRECISION
#define SL_CLOCK_MANAGER_LFRCO_PRECISION    cmuPrecisionDefault
#endif
// </h>

// </h>

#endif /* SL_CLOCK_MANAGER_OSCILLATOR_CONFIG_H */

// <<< end of configuration section >>>
