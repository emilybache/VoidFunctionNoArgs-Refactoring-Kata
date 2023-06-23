

#ifndef VOIDFUNCTIONNOARGS_CONSTANTS_H
#define VOIDFUNCTIONNOARGS_CONSTANTS_H

// enums
extern unsigned int C_IBS_NOK;
extern unsigned int C_IBS_OK;

extern unsigned int N_VALVE_CROSS;
extern unsigned int N_VALVE_DIAG;
extern unsigned int N_MANUAL;
extern unsigned int N_AUTOMATIK;

extern unsigned int STATE_WITHIN_DEADZONE;
extern unsigned int STATE_OUTSIDE_DEADZONE;
extern unsigned int STATE_MOVE_UP;
extern unsigned int STATE_MOVE_DOWN;

// bit masks
#define ZU_O 1
#define ZU_V 2
#define AUF_O 4
#define AUF_V 8
#define BO_REGLER 16
#define BV_REGLER 32
#define TOTZONE 1
#define TOTZONE_ALT 2
#define STROM_GRENZ 4
#define TY_GRENZ_1 8
#define TY_GRENZ_2 16

// Constants
#define PERCENT_MIN 34
#define PERCENT_MAX 89
#define PRAE_WIRK_1 42
#define PRAE_WIRK_2 56

#endif //VOIDFUNCTIONNOARGS_CONSTANTS_H
