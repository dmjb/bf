#include "Program.h"

Instruction Program::operator[] (size_t index) {
  switch ((*code)[index]) {
    case '>': return Instruction::NEXT;
    case '<': return Instruction::PREV;
    case '+': return Instruction::INC;
    case '-': return Instruction::DEC;
    case '.': return Instruction::PRINT;
    case ',': return Instruction::READ;
    case '[': return Instruction::FWD;
    case ']': return Instruction::BACK;
    default: return Instruction::NOOP;
  }
}

size_t Program::length() {
  return (*code).size();
}
