//
// Created by Don Browne on 14/06/15.
//

#include <iostream>
#include "Executor.h"

void Executor::run() {
    size_t length = program->length();
    for (size_t pc = 0; pc < length; pc++) {
        switch ((*program)[pc]) {
            case Instruction::NEXT: {
                state->next();
                break;
            }
            case Instruction::PREV: {
                state->prev();
                break;
            }
            case Instruction::INC: {
                state->incr();
                break;
            }
            case Instruction::DEC: {
                state->decr();
                break;
            }
            case Instruction::PRINT: {
                std::cout << state->get();
                break;
            }
            case Instruction::READ: {
                unsigned char inp;
                std::cin >> inp;
                state->assign(inp);
                break;
            }
            case Instruction::FWD: {
                if (state->get() == 0) {
                    size_t lookahead = pc;
                    // scan ahead till eof, or matching ] is found
                    while (lookahead < length && (*program)[lookahead++] != Instruction::BACK);
                    if (lookahead >= length) {
                        std::cout << "Reached end of program looking for matching ]" << std::endl;
                        exit(1);
                    } else {
                        pc = lookahead;
                    }
                } else {
                    jump_stack->push(pc);
                }
                break;
            }
            case Instruction::BACK: {
                if (jump_stack->empty()) {
                    std::cout << "Hit ] without matching [" << std::endl;
                    exit(1);
                } else if (state->get() != 0) {
                    pc = jump_stack->top();
                } else {
                    // if escaping from this loop, pop start from stack
                    jump_stack->pop();
                }
                break;
            }
            case Instruction::NOOP: {
                break;
            }
        }
    }
}
