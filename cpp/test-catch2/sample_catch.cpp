#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "sample.h"


#define PRINT_LINE(stream, x) stream << #x << " = " << x << "\n"

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
    PRINT_LINE(output, wirkFall);

    return output.str();
}

TEST_CASE ("theFunctionToTest") {
    resetState();
    SECTION("all defaults"){
        theFunctionToTest();
        ApprovalTests::Approvals::verify(printGlobals());
    }
}


