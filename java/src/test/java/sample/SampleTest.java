package sample;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import java.lang.reflect.Field;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class SampleTest {

    @Test
    void firstTest() throws IllegalAccessException {
        List<Integer> allAnsprAufO = Arrays.asList(0);
        List<Integer> allAnsprAufV = Arrays.asList(0);
        List<Integer> allAnsprBand = Arrays.asList(0);
        List<Integer> allAnsprHyst = Arrays.asList(0);
        List<Integer> allAnsprZuO = Arrays.asList(0);
        List<Integer> allAnsprZuV = Arrays.asList(0);
        List<Integer> allAutoIbsOk = Arrays.asList(0);
        List<Integer> allBinSteuer = Arrays.asList(0);
        List<Integer> allNerker1 = Arrays.asList(0);
        List<Integer> allNImpuls = Arrays.asList(0);
        List<Integer> allNRegFkt = Arrays.asList(0);
        List<Integer> allRegDiff = Arrays.asList(0);
        List<Integer> allRegDiffSch = Arrays.asList(0);
        List<Integer> allRegMode = Arrays.asList(0);
        List<Integer> allSollwertRev = Arrays.asList(0);
        List<Integer> allStellFwd = Arrays.asList(0);
        List<Integer> allStellIstRev = Arrays.asList(0);
        List<Integer> allWirkFall = Arrays.asList(0);

        for (int AnsprAufO : allAnsprAufO) {
            for (int AnsprAufV : allAnsprAufV) {
                for (int AnsprBand : allAnsprBand) {
                    for (int AnsprHyst : allAnsprHyst) {
                        for (int AnsprZuO : allAnsprZuO) {
                            for (int AnsprZuV : allAnsprZuV) {
                                for (int AutoIbsOk : allAutoIbsOk) {
                                    for (int BinSteuer : allBinSteuer) {
                                        for (int Nerker1 : allNerker1) {
                                            for (int NImpuls : allNImpuls) {
                                                for (int NRegFkt : allNRegFkt) {
                                                    for (int RegDiff : allRegDiff) {
                                                        for (int RegDiffSch : allRegDiffSch) {
                                                            for (int RegMode : allRegMode) {
                                                                for (int SollwertRev : allSollwertRev) {
                                                                    for (int StellFwd : allStellFwd) {
                                                                        for (int StellIstRev : allStellIstRev) {
                                                                            for (int WirkFall : allWirkFall) {

                                                                                // globals to something -> quick way to set from template
                                                                                Sample.theFunctionToTest();

                                                                                assertEquals(2, 1 + 1);

                                                                                String s = captureState();
                                                                                System.out.println(s);
                                                                                // assert globals to sth, quick way to read and compare
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private static String captureState() throws IllegalAccessException {
        StringBuilder state = new StringBuilder();
        Field[] fields = Globals.class.getDeclaredFields();
        Arrays.sort(fields, Comparator.comparing(Field::getName));
        for (Field field : fields) {
            state.append(field.getName());
            state.append(';');
            state.append(field.get(null));
            state.append('\n');
        }
        return state.toString();
    }

}
