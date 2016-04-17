//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_PROGRAM_H
#define BF_PROGRAM_H

#include <string>

enum class Instruction {INC, DEC, NEXT, PREV, PRINT, READ, FWD, BACK, NOOP};

class Program {
 private:
  std::string * code;
 public:
  Program(std::string * code) : code(code) {};
  ~Program() {};

  Instruction operator[] (size_t index);
  size_t length();
};

#endif //BF_PROGRAM_H
