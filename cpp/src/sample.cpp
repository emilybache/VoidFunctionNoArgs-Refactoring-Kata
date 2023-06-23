#include "sample.h"
#include "globals.h"
#include "constants.h"

extern int IstwMin;
extern int IstwMax;
extern unsigned int Zustand[2];

void theFunctionToTest() {
    int ZwspAufO;
    int ZwspZuV;
    unsigned int zw;

    if ((AutoIbsOk == C_IBS_OK) &&
        ((RegMode == N_AUTOMATIK) || (RegMode == N_VALVE_DIAG)) &&
        ((BinSteuer & BO_REGLER) != 0)) {
        StellFwd &= ~(ZU_O | ZU_V | AUF_O | AUF_V);
    } else {
        if ((NImpuls & TOTZONE) == 0) {
            NRegFkt &= ~(TOTZONE_ALT);
        } else {
            NRegFkt |= TOTZONE_ALT;
        }
        ZwspAufO = AnsprAufO;
        ZwspZuV = AnsprZuO;
        if (Zustand[0] == STATE_WITHIN_DEADZONE) {
            ZwspAufO = AnsprAufO + AnsprHyst;
            ZwspZuV = AnsprZuO - AnsprHyst;

            if (((RegDiff < AnsprZuO) && (Zustand[1] != STATE_MOVE_UP) && ((SollwertRev - IstwMin) > AnsprZuO))
                ||
                ((RegDiff > AnsprAufO) && (Zustand[1] != STATE_MOVE_DOWN) && ((SollwertRev - IstwMax) > AnsprAufO)))
            {
                ZwspAufO = AnsprAufO + AnsprBand;
                ZwspZuV = AnsprZuO - AnsprBand;
            }
        }

        if ((Nerker1 & STROM_GRENZ) != 0) {
            if (wirkFall == 0) {
                ZwspAufO = ZwspAufO + 37;
            }
            else {
                ZwspZuV = ZwspZuV - 37;
            }
        }

        if (AnsprZuV > ZwspZuV)
        {
            AnsprZuV = ZwspZuV;
        }
        if (AnsprAufV > ZwspAufO)
        {
            AnsprAufV = ZwspAufO;
        }

        StellFwd &= ~(ZU_O | ZU_V | AUF_O | AUF_V);
        int PraeAufWirk = 0;
        int PraeZuWirk = 0;

        if ((RegDiff >= ZwspZuV) && (RegDiff <= ZwspAufO))
        {
            NImpuls |= TOTZONE;
        }
        else {
            NImpuls &= ~TOTZONE;
            PraeAufWirk = AnsprAufV;
            PraeZuWirk = AnsprZuV;
        }
        if (RegDiffSch > ZwspAufO)
        {
            if (RegDiff > ZwspAufO) {
                if (RegDiffSch > AnsprAufV) {
                    StellFwd |= AUF_V;
                }
                else {
                    StellFwd |= AUF_O;
                }
            }
        }

        if (PraeAufWirk == AnsprAufV || PraeZuWirk == AnsprZuV) {
            if ((NImpuls & TOTZONE) != 0){
                if (StellIstRev < IstwMin) {
                    IstwMin = StellIstRev;
                }
                if (StellIstRev > IstwMax) {
                    IstwMax = StellIstRev;
                }
            } else {
                IstwMax = PERCENT_MIN;
                IstwMin = PERCENT_MAX;
            }

        }

        zw = Zustand[0];
        if ((NImpuls & TOTZONE) != 0) {
            zw = STATE_WITHIN_DEADZONE;
        }
        if ((StellFwd & (ZU_O | ZU_V)) != 0) {
            zw = STATE_MOVE_DOWN;
        }
        if ((StellFwd & (AUF_O | AUF_V)) != 0) {
            zw = STATE_MOVE_UP;
        }

        if (zw != Zustand[0])
        {
            Zustand[1] = Zustand[0];
            Zustand[0] = zw;
        }
    }

}

