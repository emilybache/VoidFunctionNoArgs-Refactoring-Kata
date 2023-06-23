#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "sample.h"


#define PRINT_LINE(stream, x) if (x != 0) {stream << #x << " = " << x << "\n";}

std::string printGlobals() {
    std::ostringstream output;
    PRINT_LINE(output, AnsprAufO);
    PRINT_LINE(output, AnsprAufV);
    PRINT_LINE(output, AnsprBand);
    PRINT_LINE(output, AnsprHyst);
    PRINT_LINE(output, AnsprZuO);
    PRINT_LINE(output, AnsprZuV);
    PRINT_LINE(output, AutoIbsOk);
    PRINT_LINE(output, BinSteuer);
    PRINT_LINE(output, Nerker1);
    PRINT_LINE(output, NImpuls);
    PRINT_LINE(output, NRegFkt);
    PRINT_LINE(output, RegDiff);
    PRINT_LINE(output, RegDiffSch);
    PRINT_LINE(output, RegMode);
    PRINT_LINE(output, SollwertRev);
    PRINT_LINE(output, StellFwd);
    PRINT_LINE(output, StellIstRev);
    PRINT_LINE(output, WirkFall);

    return output.str();
}


TEST_CASE ("theFunctionToTest") {
    resetState();
    SECTION("all defaults") {
        theFunctionToTest();
        ApprovalTests::Approvals::verify(printGlobals());
    }
    SECTION("all combinations") {

        std::vector<int> AnsprAufOs{0, 1};
        std::vector<int> AnsprAufVs{0, 1};
        std::vector<int> AnsprBands{0, 1};
        std::vector<int> AnsprHysts{0, 1};
        std::vector<int> AnsprZuOs{0, 1};
        std::vector<int> AnsprZuVs{0, 1};
        std::vector<unsigned int> AutoIbsOks{0, C_IBS_OK};
        std::vector<unsigned int> BinSteuers{0, 16};
        std::vector<int> Nerker1s{0, 4};
        std::vector<unsigned int> NImpulss{0, 63};
        std::vector<unsigned int> NRegFkts{0};
        std::vector<int> RegDiffs{0, -37, 37};
        std::vector<int> RegDiffSchs{0, 5, 100};
        std::vector<unsigned int> RegModes{0, N_AUTOMATIK, N_VALVE_DIAG};
        std::vector<int> SollwertRevs{0, 50};
        std::vector<int> StellFwds{0, 13};
        std::vector<int> StellIstRevs{0, 100};
        std::vector<int> wirkFalls{0, 1};
        ApprovalTests::CombinationApprovals::verifyAllCombinations(
                "theFunctionToTest all combinations of globals",
                [&](
                        auto ansprAufO,
                        auto ansprAufV,
                        auto ansprBand,
                        auto ansprHyst,
                        auto ansprZuO,
                        auto ansprZuV,
                        auto autoIbsOk,
                        auto binSteuer,
                        auto nerker1,
                        auto nImpuls,
                        auto nRegFkt,
                        auto regDiff,
                        auto regDiffSch,
                        auto regMode,
                        auto sollwertRev,
                        auto stellFwd,
                        auto stellIstRev,
                        auto wirkFall
                ) {
                    AnsprAufO = ansprAufO;
                    AnsprAufV = ansprAufV;
                    AnsprBand = ansprBand;
                    AnsprHyst = ansprHyst;
                    AnsprZuO = ansprZuO;
                    AnsprZuV = ansprZuV;
                    AutoIbsOk = autoIbsOk;
                    BinSteuer = binSteuer;
                    Nerker1 = nerker1;
                    NImpuls = nImpuls;
                    NRegFkt = nRegFkt;
                    RegDiff = regDiff;
                    RegDiffSch = regDiffSch;
                    RegMode = regMode;
                    SollwertRev = sollwertRev;
                    StellFwd = stellFwd;
                    StellIstRev = stellIstRev;
                    WirkFall = wirkFall;

                    std::string before = "\n" + printGlobals();

                    theFunctionToTest();

                    return before + "->\n" + printGlobals();
                },
                AnsprAufOs,
                AnsprAufVs,
                AnsprBands,
                AnsprHysts,
                AnsprZuOs,
                AnsprZuVs,
                AutoIbsOks,
                BinSteuers,
                Nerker1s,
                NImpulss,
                NRegFkts,
                RegDiffs,
                RegDiffSchs,
                RegModes,
                SollwertRevs,
                StellFwds,
                StellIstRevs,
                wirkFalls
        );

    }
}


