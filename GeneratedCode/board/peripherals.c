/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v12.0
processor: MKE18F256xxx16
package_id: MKE18F256VLH16
mcu_data: ksdk2_0
processor_version: 13.0.1
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 07f5b299-ddc0-4be9-99fd-d197ad5ead68
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DMA initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DMA'
- type: 'edma'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'edma_6d0dd4e17e2f179c7d42d98767129ede'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DMA'
- config_sets:
  - fsl_edma:
    - common_settings:
      - enableContinuousLinkMode: 'true'
      - enableHaltOnError: 'true'
      - enableRoundRobinArbitration: 'false'
      - enableDebugMode: 'false'
    - dma_table:
      - 0: []
      - 1: []
      - 2: []
    - edma_channels:
      - 0:
        - apiMode: 'nontransTCD'
        - edma_channel:
          - channel_prefix_id: 'CH0'
          - uid: '1692661534018'
          - eDMAn: '2'
          - eDMA_source: 'kDmaRequestMux0ADC0'
          - enableTriggerInput: 'true'
          - init_channel_priority: 'false'
          - edma_channel_Preemption:
            - enableChannelPreemption: 'false'
            - enablePreemptAbility: 'false'
            - channelPriority: '0'
        - resetChannel: 'false'
        - enableChannelRequest: 'true'
        - enableAsyncRequest: 'false'
        - tcd_configuration: []
        - constantTCD: 'false'
        - initializedTCD: '0'
        - irqSources: ''
        - init_interruptsEnable: 'false'
        - interrupt_channel:
          - IRQn: 'DMA2_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'false'
          - priority: '0'
          - enable_custom_name: 'false'
    - errInterruptConfig:
      - enableErrInterrupt: 'false'
      - errorInterrupt:
        - IRQn: 'DMA_Error_IRQn'
        - enable_interrrupt: 'enabled'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const edma_config_t DMA_config = {
        .enableContinuousLinkMode = true,
        .enableHaltOnError = true,
        .enableRoundRobinArbitration = false,
        .enableDebugMode = false
};

static void DMA_init(void) {

    /* Channel CH0 initialization */
    /* Set the source kDmaRequestMux0ADC0 request in the DMAMUX */
    DMAMUX_SetSource(DMA_DMAMUX_BASEADDR, DMA_CH0_DMA_CHANNEL, DMA_CH0_DMA_REQUEST);
    /* Set the DMA channel 2 periodic trigger */
    DMAMUX_EnablePeriodTrigger(DMA_DMAMUX_BASEADDR, DMA_CH0_DMA_CHANNEL);
    /* Enable the channel 2 in the DMAMUX */
    DMAMUX_EnableChannel(DMA_DMAMUX_BASEADDR, DMA_CH0_DMA_CHANNEL);
    /* DMA channel 2 peripheral request */
    EDMA_EnableChannelRequest(DMA_DMA_BASEADDR, DMA_CH0_DMA_CHANNEL);
}

/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
      - 1: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * CAN0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CAN0'
- type: 'flexcan'
- mode: 'interrupts'
- custom_name_enabled: 'false'
- type_id: 'flexcan_477f6be3462ee2961b67c0825ef495e2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CAN0'
- config_sets:
  - interruptsCfg:
    - messageBufferIrqs: '0'
    - interruptsEnable: ''
    - enable_ored_mb_irq: 'false'
    - interrupt_ored_mb:
      - IRQn: 'CAN0_ORed_Message_buffer_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '1'
      - enable_custom_name: 'false'
    - enable_busoff_irq: 'false'
    - interrupt_busoff:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_error_irq: 'false'
    - interrupt_error:
      - IRQn: 'CAN0_Error_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_tx_irq: 'false'
    - interrupt_tx:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_rx_irq: 'false'
    - interrupt_rx:
      - IRQn: 'CAN0_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_wakeup_irq: 'false'
    - interrupt_wakeup:
      - IRQn: 'CAN0_Wake_Up_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
  - fsl_flexcan:
    - can_config:
      - clockSource: 'kFLEXCAN_ClkSrcPeri'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - wakeupSrc: 'kFLEXCAN_WakeupSrcUnfiltered'
      - baudRate: '500000'
      - maxMbNum: '16'
      - enableLoopBack: 'false'
      - enableTimerSync: 'true'
      - enableSelfWakeup: 'false'
      - enableIndividMask: 'false'
      - disableSelfReception: 'false'
      - enableListenOnlyMode: 'false'
      - timingConfig:
        - propSeg: '7'
        - phaseSeg1: '4'
        - phaseSeg2: '2'
        - rJumpwidth: '2'
        - bitTime: []
    - enableRxFIFO: 'false'
    - rxFIFO:
      - idFilterTable: ''
      - idFilterNum: 'num0'
      - idFilterType: 'kFLEXCAN_RxFifoFilterTypeA'
      - priority: 'kFLEXCAN_RxFifoPrioLow'
    - channels:
      - 0:
        - mbID: '0'
        - mbType: 'mbRx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
      - 1:
        - mbID: '1'
        - mbType: 'mbTx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const flexcan_config_t CAN0_config = {
        .clkSrc = kFLEXCAN_ClkSrc1,
        .wakeupSrc = kFLEXCAN_WakeupSrcUnfiltered,
        .baudRate = 500000UL,
        .maxMbNum = 16U,
        .enableLoopBack = false,
        .enableTimerSync = true,
        .enableSelfWakeup = false,
        .enableIndividMask = false,
        .disableSelfReception = false,
        .enableListenOnlyMode = false,
        .timingConfig = {
                .preDivider = 11,
    .propSeg = 6,
    .phaseSeg1 = 3,
    .phaseSeg2 = 1,
    .rJumpwidth = 1
  }
};
/* Message buffer 0 configuration structure */
const flexcan_rx_mb_config_t CAN0_rx_mb_config_0 = {
  .id = FLEXCAN_ID_STD(0UL),
  .format = kFLEXCAN_FrameFormatStandard,
  .type = kFLEXCAN_FrameTypeData
};

static void CAN0_init(void) {
  FLEXCAN_Init(CAN0_PERIPHERAL, &CAN0_config, CAN0_CLOCK_SOURCE);

  /* Message buffer 0 initialization */
  FLEXCAN_SetRxMbConfig(CAN0_PERIPHERAL, 0, &CAN0_rx_mb_config_0, true);
  /* Message buffer 1 initialization */
  FLEXCAN_SetTxMbConfig(CAN0_PERIPHERAL, 1, true);
}

/***********************************************************************************************************************
 * LPSPI0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPSPI0'
- type: 'lpspi'
- mode: 'freertos'
- custom_name_enabled: 'false'
- type_id: 'lpspi_6e21a1e0a09f0a012d683c4f91752db8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPSPI0'
- config_sets:
  - transfer:
    - config:
      - transmitBuffer:
        - init: 'false'
      - receiveBuffer:
        - init: 'false'
      - dataSize: '10'
      - enableTransferStruct: 'defined'
      - flags: ''
  - main:
    - mode: 'kLPSPI_Master'
    - clockSource: 'LpspiClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - master:
      - baudRate: '2000000'
      - bitsPerFrame: '8'
      - cpol: 'kLPSPI_ClockPolarityActiveHigh'
      - cpha: 'kLPSPI_ClockPhaseSecondEdge'
      - direction: 'kLPSPI_MsbFirst'
      - pcsToSckDelayInNanoSec: '1000'
      - lastSckToPcsDelayInNanoSec: '1000'
      - betweenTransferDelayInNanoSec: '1000'
      - whichPcs: 'kLPSPI_Pcs0'
      - pcsActiveHighOrLow: 'kLPSPI_PcsActiveLow'
      - pinCfg: 'kLPSPI_SdiInSdoOut'
      - dataOutConfig: 'kLpspiDataOutRetained'
    - allPcsPolarityEnable: 'false'
    - allPcsPolarity:
      - kLPSPI_Pcs1Active: 'kLPSPI_PcsActiveLow'
      - kLPSPI_Pcs2Active: 'kLPSPI_PcsActiveLow'
      - kLPSPI_Pcs3Active: 'kLPSPI_PcsActiveLow'
    - interrupt_priority:
      - IRQn: 'LPSPI0_IRQn'
      - enable_priority: 'true'
      - priority: '5'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpspi_master_config_t LPSPI0_config = {
  .baudRate = 2000000UL,
  .bitsPerFrame = 8UL,
  .cpol = kLPSPI_ClockPolarityActiveHigh,
  .cpha = kLPSPI_ClockPhaseSecondEdge,
  .direction = kLPSPI_MsbFirst,
  .pcsToSckDelayInNanoSec = 1000UL,
  .lastSckToPcsDelayInNanoSec = 1000UL,
  .betweenTransferDelayInNanoSec = 1000UL,
  .whichPcs = kLPSPI_Pcs0,
  .pcsActiveHighOrLow = kLPSPI_PcsActiveLow,
  .pinCfg = kLPSPI_SdiInSdoOut,
  .dataOutConfig = kLpspiDataOutRetained
};
lpspi_transfer_t LPSPI0_transfer = {
  .txData = NULL,
  .rxData = NULL,
  .dataSize = 10,
  .configFlags = 0
};
lpspi_rtos_handle_t LPSPI0_handle;

static void LPSPI0_init(void) {
  /* Interrupt vector LPSPI0_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(LPSPI0_IRQN, LPSPI0_IRQ_PRIORITY);
  LPSPI_RTOS_Init(&LPSPI0_handle, LPSPI0_PERIPHERAL, &LPSPI0_config, LPSPI0_CLOCK_FREQ);
}

/***********************************************************************************************************************
 * FTM3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FTM3'
- type: 'ftm'
- mode: 'EdgeAligned'
- custom_name_enabled: 'false'
- type_id: 'ftm_cf73470dab578a761c1bb272554a7d11'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FTM3'
- config_sets:
  - ftm_main_config:
    - ftm_config:
      - clockSource: 'kFTM_FixedClock'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
      - timerPrescaler: '4'
      - timerOutputFrequency: '0xfffe'
      - systemClockSource: 'BusInterfaceClock'
      - systemClockSourceFreq: 'ClocksTool_DefaultInit'
      - faultMode: 'kFTM_Fault_Disable'
      - inputFilterPeriod: '1'
      - faultInputs:
        - 0:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 1:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 2:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
        - 3:
          - enableFaultInput: 'false'
          - faultLevelVal: 'low'
          - useFaultFilter: 'false'
      - deadTimePrescale: 'kFTM_Deadtime_Prescale_1'
      - deadTimePeriod: '0'
      - pwmSyncMode: 'kFTM_SoftwareTrigger'
      - reloadPoints: ''
      - extTriggers: ''
      - chnlInitState: ''
      - chnlPolarity: ''
      - bdmMode: 'kFTM_BdmMode_3'
      - useGlobalTimeBase: 'false'
    - timer_interrupts: ''
    - enable_irq: 'true'
    - ftm_interrupt:
      - IRQn: 'FTM3_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '1'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'false'
  - ftm_edge_aligned_mode:
    - ftm_edge_aligned_channels_config:
      - 0:
        - channelId: ''
        - edge_aligned_mode: 'kFTM_OutputCompare'
        - output_compare:
          - chnNumber: 'kFTM_Chnl_2'
          - output_compare_mode: 'kFTM_ToggleOnMatch'
          - compareValueStr: '0'
          - enable_chan_irq: 'false'
      - 1:
        - channelId: ''
        - edge_aligned_mode: 'kFTM_InputCapture'
        - input_capture:
          - chnNumber: 'kFTM_Chnl_3'
          - input_capture_edge: 'kFTM_RiseAndFallEdge'
          - inputFilterPeriod: '1'
          - enable_chan_irq: 'true'
      - 2:
        - channelId: ''
        - edge_aligned_mode: 'kFTM_OutputCompare'
        - output_compare:
          - chnNumber: 'kFTM_Chnl_0'
          - output_compare_mode: 'kFTM_NoOutputSignal'
          - compareValueStr: '0'
          - enable_chan_irq: 'true'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ftm_config_t FTM3_config = {
        .prescale = kFTM_Prescale_Divide_4,
        .faultMode = kFTM_Fault_Disable,
        .faultFilterValue = 0,
        .deadTimePrescale = kFTM_Deadtime_Prescale_1,
        .deadTimeValue = 0,
        .pwmSyncMode = kFTM_SoftwareTrigger,
        .reloadPoints = 0,
        .extTriggers = 0,
        .chnlInitState = 0,
        .chnlPolarity = 0,
        .bdmMode = kFTM_BdmMode_3,
        .useGlobalTimeBase = false
};

static void FTM3_init(void) {
    FTM_Init(FTM3_PERIPHERAL, &FTM3_config);
    FTM_SetTimerPeriod(FTM3_PERIPHERAL, FTM3_TIMER_MODULO_VALUE);
    FTM_SetupOutputCompare(FTM3_PERIPHERAL, kFTM_Chnl_2, kFTM_ToggleOnMatch, 0U);
    FTM_SetupInputCapture(FTM3_PERIPHERAL, kFTM_Chnl_3, kFTM_RiseAndFallEdge, 0);
    FTM_SetupOutputCompare(FTM3_PERIPHERAL, kFTM_Chnl_0, kFTM_NoOutputSignal, 0U);
    FTM_EnableInterrupts(FTM3_PERIPHERAL, kFTM_Chnl3InterruptEnable | kFTM_Chnl0InterruptEnable);
    /* Interrupt vector FTM3_IRQn priority settings in the NVIC. */
    NVIC_SetPriority(FTM3_IRQN, FTM3_IRQ_PRIORITY);
    /* Enable interrupt FTM3_IRQn request in the NVIC. */
    EnableIRQ(FTM3_IRQN);
}

/***********************************************************************************************************************
 * LPUART0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART0'
- type: 'lpuart'
- mode: 'edma'
- custom_name_enabled: 'false'
- type_id: 'lpuart_54a65a580e3462acdbacefd5299e0cac'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART0'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'ClocksTool_DefaultInit'
      - baudRate_Bps: '115200'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
  - edmaCfg:
    - edma_channels:
      - enable_rx_edma_channel: 'true'
      - edma_rx_channel:
        - uid: '1692683194258'
        - eDMAn: '0'
        - eDMA_source: 'kDmaRequestMux0LPUART0Rx'
        - enableTriggerInput: 'false'
        - init_channel_priority: 'false'
        - edma_channel_Preemption:
          - enableChannelPreemption: 'false'
          - enablePreemptAbility: 'false'
          - channelPriority: '0'
        - enable_custom_name: 'false'
      - enable_tx_edma_channel: 'true'
      - edma_tx_channel:
        - uid: '1692683194261'
        - eDMAn: '1'
        - eDMA_source: 'kDmaRequestMux0LPUART0Tx'
        - enableTriggerInput: 'false'
        - init_channel_priority: 'false'
        - edma_channel_Preemption:
          - enableChannelPreemption: 'false'
          - enablePreemptAbility: 'false'
          - channelPriority: '0'
        - enable_custom_name: 'false'
    - lpuart_edma_handle:
      - enable_custom_name: 'false'
      - init_callback: 'false'
      - callback_fcn: ''
      - user_data: ''
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART0_config = {
        .baudRate_Bps = 115200UL,
        .parityMode = kLPUART_ParityDisabled,
        .dataBitsCount = kLPUART_EightDataBits,
        .isMsb = false,
        .stopBitCount = kLPUART_OneStopBit,
        .txFifoWatermark = 0U,
        .rxFifoWatermark = 1U,
        .enableRxRTS = false,
        .enableTxCTS = false,
        .txCtsSource = kLPUART_CtsSourcePin,
        .txCtsConfig = kLPUART_CtsSampleAtStart,
        .rxIdleType = kLPUART_IdleTypeStartBit,
        .rxIdleConfig = kLPUART_IdleCharacter1,
        .enableTx = true,
        .enableRx = true
};
edma_handle_t LPUART0_RX_Handle;
edma_handle_t LPUART0_TX_Handle;
lpuart_edma_handle_t LPUART0_LPUART_eDMA_Handle;

static void LPUART0_init(void) {
    LPUART_Init(LPUART0_PERIPHERAL, &LPUART0_config, LPUART0_CLOCK_SOURCE);
    /* Set the source kDmaRequestMux0LPUART0Rx request in the DMAMUX */
    DMAMUX_SetSource(LPUART0_RX_DMAMUX_BASEADDR, LPUART0_RX_DMA_CHANNEL, LPUART0_RX_DMA_REQUEST);
    /* Enable the channel 0 in the DMAMUX */
    DMAMUX_EnableChannel(LPUART0_RX_DMAMUX_BASEADDR, LPUART0_RX_DMA_CHANNEL);
    /* Set the source kDmaRequestMux0LPUART0Tx request in the DMAMUX */
    DMAMUX_SetSource(LPUART0_TX_DMAMUX_BASEADDR, LPUART0_TX_DMA_CHANNEL, LPUART0_TX_DMA_REQUEST);
    /* Enable the channel 1 in the DMAMUX */
    DMAMUX_EnableChannel(LPUART0_TX_DMAMUX_BASEADDR, LPUART0_TX_DMA_CHANNEL);
    /* Create the eDMA LPUART0_RX_Handle handle */
    EDMA_CreateHandle(&LPUART0_RX_Handle, LPUART0_RX_DMA_BASEADDR, LPUART0_RX_DMA_CHANNEL);
    /* Create the eDMA LPUART0_TX_Handle handle */
    EDMA_CreateHandle(&LPUART0_TX_Handle, LPUART0_TX_DMA_BASEADDR, LPUART0_TX_DMA_CHANNEL);
  /* Create the LPUART eDMA handle */
  LPUART_TransferCreateHandleEDMA(LPUART0_PERIPHERAL, &LPUART0_LPUART_eDMA_Handle, NULL, NULL, &LPUART0_TX_Handle, &LPUART0_RX_Handle);
}

/***********************************************************************************************************************
 * CAN1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CAN1'
- type: 'flexcan'
- mode: 'interrupts'
- custom_name_enabled: 'false'
- type_id: 'flexcan_477f6be3462ee2961b67c0825ef495e2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CAN1'
- config_sets:
  - interruptsCfg:
    - messageBufferIrqs: '0'
    - interruptsEnable: ''
    - enable_ored_mb_irq: 'false'
    - interrupt_ored_mb:
      - IRQn: 'CAN1_ORed_Message_buffer_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'true'
      - priority: '1'
      - enable_custom_name: 'false'
    - enable_busoff_irq: 'false'
    - interrupt_busoff:
      - IRQn: 'CAN1_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_error_irq: 'false'
    - interrupt_error:
      - IRQn: 'CAN1_Error_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_tx_irq: 'false'
    - interrupt_tx:
      - IRQn: 'CAN1_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_rx_irq: 'false'
    - interrupt_rx:
      - IRQn: 'CAN1_ORed_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_wakeup_irq: 'false'
    - interrupt_wakeup:
      - IRQn: 'CAN1_Wake_Up_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
  - fsl_flexcan:
    - can_config:
      - clockSource: 'kFLEXCAN_ClkSrcPeri'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - wakeupSrc: 'kFLEXCAN_WakeupSrcUnfiltered'
      - baudRate: '500000'
      - maxMbNum: '16'
      - enableLoopBack: 'false'
      - enableTimerSync: 'true'
      - enableSelfWakeup: 'false'
      - enableIndividMask: 'false'
      - disableSelfReception: 'false'
      - enableListenOnlyMode: 'false'
      - timingConfig:
        - propSeg: '7'
        - phaseSeg1: '4'
        - phaseSeg2: '2'
        - rJumpwidth: '2'
        - bitTime: []
    - enableRxFIFO: 'false'
    - rxFIFO:
      - idFilterTable: ''
      - idFilterNum: 'num0'
      - idFilterType: 'kFLEXCAN_RxFifoFilterTypeA'
      - priority: 'kFLEXCAN_RxFifoPrioLow'
    - channels:
      - 0:
        - mbID: '0'
        - mbType: 'mbRx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
      - 1:
        - mbID: '1'
        - mbType: 'mbTx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const flexcan_config_t CAN1_config = {
        .clkSrc = kFLEXCAN_ClkSrc1,
        .wakeupSrc = kFLEXCAN_WakeupSrcUnfiltered,
        .baudRate = 500000UL,
        .maxMbNum = 16U,
        .enableLoopBack = false,
        .enableTimerSync = true,
        .enableSelfWakeup = false,
        .enableIndividMask = false,
        .disableSelfReception = false,
        .enableListenOnlyMode = false,
        .timingConfig = {
                .preDivider = 11,
                .propSeg = 6,
                .phaseSeg1 = 3,
                .phaseSeg2 = 1,
                .rJumpwidth = 1
        }
};
/* Message buffer 0 configuration structure */
const flexcan_rx_mb_config_t CAN1_rx_mb_config_0 = {
        .id = FLEXCAN_ID_STD(0UL),
        .format = kFLEXCAN_FrameFormatStandard,
        .type = kFLEXCAN_FrameTypeData
};

static void CAN1_init(void) {
    FLEXCAN_Init(CAN1_PERIPHERAL, &CAN1_config, CAN1_CLOCK_SOURCE);

    /* Message buffer 0 initialization */
    FLEXCAN_SetRxMbConfig(CAN1_PERIPHERAL, 0, &CAN1_rx_mb_config_0, true);
    /* Message buffer 1 initialization */
    FLEXCAN_SetTxMbConfig(CAN1_PERIPHERAL, 1, true);
}

/***********************************************************************************************************************
 * ADC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'ADC0'
- type: 'adc12'
- mode: 'ADC12'
- custom_name_enabled: 'false'
- type_id: 'adc12_5324d28dd0212c08055a9d9cd4317082'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'ADC0'
- config_sets:
  - fsl_adc12:
    - enable_irq: 'false'
    - adc_interrupt:
      - IRQn: 'ADC0_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - adc12_config:
      - referenceVoltageSource: 'kADC12_ReferenceVoltageSourceVref'
      - clockSource: 'kADC12_ClockSourceAlt0'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
      - clockDivider: 'kADC12_ClockDivider2'
      - resolution: 'kADC12_Resolution12Bit'
      - sampleClockCount: '13'
      - enableContinuousConversion: 'true'
    - adc12HardwareCompareConfig:
      - hardwareCompareModeEnable: 'false'
    - adc12_hardware_average_mode: 'kADC12_HardwareAverageCount16'
    - hardwareTrigger: 'true'
    - enableDMA: 'true'
    - doAutoCalibration: 'true'
    - offset: '0'
    - gain: '0'
    - adc12_channels_config:
      - 0:
        - channelName: ''
        - channelNumber: 'SE.15'
        - enableInterruptOnConversionCompleted: 'false'
      - 1:
        - channelName: ''
        - channelNumber: 'SE.9'
        - enableInterruptOnConversionCompleted: 'false'
      - 2:
        - channelName: ''
        - channelNumber: 'SE.8'
        - enableInterruptOnConversionCompleted: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const adc12_config_t ADC0_config = {
        .referenceVoltageSource = kADC12_ReferenceVoltageSourceVref,
        .clockSource = kADC12_ClockSourceAlt0,
        .clockDivider = kADC12_ClockDivider2,
        .resolution = kADC12_Resolution12Bit,
        .sampleClockCount = 13UL,
        .enableContinuousConversion = true
};
adc12_channel_config_t ADC0_channelsConfig[3] = {
        {
                .channelNumber = 15U,
                .enableInterruptOnConversionCompleted = false
        },
        {
                .channelNumber = 9U,
                .enableInterruptOnConversionCompleted = false
        },
        {
                .channelNumber = 8U,
                .enableInterruptOnConversionCompleted = false
        }
};
const adc12_hardware_average_mode_t ADC0_hardwareAverageConfig = kADC12_HardwareAverageCount16;

static void ADC0_init(void) {
    /* Initialize ADC12 converter */
    ADC12_Init(ADC0_PERIPHERAL, &ADC0_config);
    /* Set to hardware trigger mode */
    ADC12_EnableHardwareTrigger(ADC0_PERIPHERAL, true);
    /* Configure hardware average mode */
    ADC12_SetHardwareAverage(ADC0_PERIPHERAL, ADC0_hardwareAverageConfig);
    /* Set the offset value for the conversion result */
    ADC12_SetOffsetValue(ADC0_PERIPHERAL, (uint32_t) 0);
    /* Set the gain value for the conversion result */
    ADC12_SetGainValue(ADC0_PERIPHERAL, 0);
    /* Perform auto calibration */
    ADC12_DoAutoCalibration(ADC0_PERIPHERAL);
    /* Enable generating the DMA trigger when conversion is completed */
    ADC12_EnableDMA(ADC0_PERIPHERAL, true);
}

/***********************************************************************************************************************
 * LPIT0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPIT0'
- type: 'lpit'
- mode: 'LPIT_GENERAL'
- custom_name_enabled: 'false'
- type_id: 'lpit_8e4186d834c8d9f4b6c0dadcc9dc2f05'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPIT0'
- config_sets:
  - fsl_lpit:
    - lpitConfig:
      - enableRunInDebug: 'false'
      - enableRunInDoze: 'false'
    - timingConfig:
      - clockSource: 'AsyncPeripheralClock'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
    - channels:
      - 0:
        - lpitChannelPrefixID: 'Channel_0'
        - channelNumber: '0'
        - enableChain: 'false'
        - timerMode: 'kLPIT_PeriodicCounter'
        - timerPeriod: '1khz'
        - lpit_trigger_select_t: 'internal_trigger_0'
        - enableReloadOnTriggerBool: 'true'
        - enableStopOnTimeout: 'false'
        - enableStartOnTriggerBool: 'false'
        - startTimer: 'false'
        - enableInterrupt: 'false'
        - interrupt:
          - IRQn: 'LPIT0_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'false'
          - priority: '0'
          - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpit_chnl_params_t LPIT0_Channel_0_struct = {
        .chainChannel = false,
        .timerMode = kLPIT_PeriodicCounter,
        .triggerSource = kLPIT_TriggerSource_Internal,
        .triggerSelect = kLPIT_Trigger_TimerChn0,
        .enableReloadOnTrigger = true,
        .enableStopOnTimeout = false,
        .enableStartOnTrigger = false
};
const lpit_config_t LPIT0_config = {
        .enableRunInDebug = false,
        .enableRunInDoze = false
};

static void LPIT0_init(void) {
    /* Initialize the LPIT. */
    LPIT_Init(LPIT0_PERIPHERAL, &LPIT0_config);
    /* Setup channel 0. */
    LPIT_SetupChannel(LPIT0_PERIPHERAL, LPIT0_CHANNEL_0, &LPIT0_Channel_0_struct);
    /* Set channel 0 period to 12000 ticks. */
    LPIT_SetTimerPeriod(LPIT0_PERIPHERAL, LPIT0_CHANNEL_0, LPIT0_CHANNEL_0_TICKS);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Global initialization */
  DMAMUX_Init(DMA_DMAMUX_BASEADDR);
  EDMA_Init(DMA_DMA_BASEADDR, &DMA_config);

  /* Initialize components */
    DMA_init();
  CAN0_init();
  LPSPI0_init();
  FTM3_init();
  LPUART0_init();
  CAN1_init();
  ADC0_init();
    LPIT0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
