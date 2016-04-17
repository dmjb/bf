//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_EXECUTOR_H
#define BF_EXECUTOR_H

#include <stack>
#include <string>
#include "State.h"
#include "Program.h"

class Executor {
private:
    std::stack<size_t> * jump_stack;
    State * state;
    Program * program;
public:
    Executor(State * state, Program * program): state(state), program(program) {
        jump_stack = new std::stack<size_t>();
    }
    ~Executor() { delete jump_stack; };

    void run();
};

#endif //BF_EXECUTOR_H
