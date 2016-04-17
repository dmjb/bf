#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Executor.h"

using namespace std;

int main() {
    State state(30000);
    std::ifstream t("prog.bf");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string prog = buffer.str();
    Program program(&prog);
    Executor executor(&state, &program);
    executor.run();
    return 0;
}
