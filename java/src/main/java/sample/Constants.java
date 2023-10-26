package sample;
public class Constants {
    // enums
    public static int C_IBS_NOK = 0;
    public static int C_IBS_OK = 1;

    public static int N_VALVE_CROSS = 0;
    public static int N_VALVE_DIAG = 1;
    public static int N_MANUAL = 2;
    public static int N_AUTOMATIK = 3;

    public static int STATE_OUTSIDE_DEADZONE = 0;
    public static int STATE_WITHIN_DEADZONE = 1;
    public static int STATE_MOVE_UP = 3;
    public static int STATE_MOVE_DOWN = 4;

    // bit masks
    public static final int ZU_O = 1;
    public static final int ZU_V = 2;
    public static final int AUF_O = 4;
    public static final int AUF_V = 8;
    public static final int BO_REGLER = 16;
    public static final int BV_REGLER = 32;
    public static final int TOTZONE = 1;
    public static final int TOTZONE_ALT = 2;
    public static final int STROM_GRENZ = 4;
    public static final int TY_GRENZ_1 = 8;
    public static final int TY_GRENZ_2 = 16;

    // constants
    public static final int PERCENT_MIN = 34;
    public static final int PERCENT_MAX = 89;
    public static final int PRAE_WIRK_1 = 42;
    public static final int PRAE_WIRK_2 = 56;
}
