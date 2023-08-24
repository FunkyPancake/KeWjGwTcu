/*
 * Copyright (c) 2023, FunkyPuncake
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef J1850_VPW_H
#define J1850_VPW_H

#include <cstdint>
#include <array>
#include "fsl_device_registers.h"


/*Lazy implementation - viable only for single instance, based on FTM3
 * CH3 -> Rx
 * CH2 -> Tx
 * CH0 -> SOF/EOF detection
 */

namespace App::CDD {
#define TX_BUFLEN   12
#define US2TICKS(x) ((uint16_t)(x*3))

/*timing thresholds for symbols*/
#define RX_SHORT_MIN US2TICKS(34)
#define RX_SHORT_MAX US2TICKS(96)
#define RX_LONG_MIN  US2TICKS(96)
#define RX_LONG_MAX  US2TICKS(163)
#define RX_SOF_MIN   US2TICKS(163)
#define RX_SOF_MAX   US2TICKS(239)
#define RX_EOF_MIN   US2TICKS(239)
#define RX_EOF_MAX   US2TICKS(280)

#define SOF_US       200
#define LONG_US      128
#define SHORT_US     64
#define EOF_US       280

#define LONG_IDX  0
#define SHORT_IDX 1
#define SOF_IDX   2
#define EOF_IDX   3


    class Vpw {
    public:
        Vpw();

        std::vector<uint8_t> GetData();

        void SendData(const std::vector<uint8_t> &data);

    private:
        static constexpr int MaxDataSize = 15;
        static constexpr uint16_t CompareDisabled = UINT16_MAX;
        static constexpr uint32_t CounterMax = CompareDisabled - 1;
        static const std::array<uint8_t, 256> _crcTable;

        enum class Status {
            Idle,
            Sof,
            Active,
            Eof,
            Failed
        };

        struct Message
        {
            uint8_t Len;
            std::array<uint8_t, MaxDataSize> Data;
        };

        struct MessageQueue {
            uint16_t CurrentIdx;
            uint16_t LastIdx;
            std::array<Message, 7> Queue;
        };

        MessageQueue _rxFifo{.CurrentIdx = 0, .LastIdx=0};
        MessageQueue _txFifo{.CurrentIdx = 0, .LastIdx=0};

        Message _txMessageBuffer{};
        int8_t _txBitInBytePos{};
        uint8_t _txBuffByte{};
        uint8_t _txLastSym{};
        uint8_t _txLastBit{};


        Message _rxMessageBuffer{};
        int8_t _rxBitInBytePos{};
        uint8_t _rxBuffByte{};
        uint8_t _rxLastSym{};
        uint8_t _rxLastBit{};


        Status _txStatus{Status::Idle}
        , _rxStatus{Status::Idle};

        uint8_t VPW_TxBuf[(TX_BUFLEN + 1) * 8]{};


        uint32_t OnTimerEvent(uint32_t status);

        static uint8_t CalcCrc(const std::vector<uint8_t> &data);

        volatile uint32_t *OutputChnCompareValue{&FTM3->CONTROLS[2].CnV};
        volatile uint32_t *EofChnCompareValue{&FTM3->CONTROLS[0].CnV};

        static void SetTimerAlarm(volatile uint32_t *counterRegister, uint32_t value);

        [[nodiscard]] static uint16_t GetPulseWidth(uint16_t a, uint16_t b);

        void ResetRx();

        void FinalizeTx();


        uint32_t PrevCntrVal{0};

    };
}// namespace App::J1850Vpw

#endif//J1850_VPW_H