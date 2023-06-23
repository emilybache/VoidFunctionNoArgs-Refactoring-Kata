

#ifndef VOIDFUNCTIONNOARGS_CONSTANTS_H
#define VOIDFUNCTIONNOARGS_CONSTANTS_H

// enums
int C_IBS_NOK = 0;
int C_IBS_OK = 1;

int N_VALVE_CROSS = 0;
int N_VALVE_DIAG = 1;
int N_MANUAL = 2;
int N_AUTOMATIK = 3;

int STATE_WITHIN_DEADZONE = 0;
int STATE_OUTSIDE_DEADZONE = 1;
int STATE_MOVE_UP = 3;
int STATE_MOVE_DOWN = 4;

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
