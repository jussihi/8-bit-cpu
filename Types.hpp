#pragma once

#include <cstdint>

typedef uint8_t byte;

enum ParamType {
  REGISTER,
  ADDRESS,
  CONSTANT,
  NONE
};

struct OpCode {
  std::string AssemblyPresentation;
  byte MachineCode;
  ParamType Param1;
  ParamType Param2;
  OpCode(std::string presentation, byte code, ParamType param1, ParamType param2) : AssemblyPresentation(presentation), MachineCode(code), Param1(param1), Param2(param2) {}
  OpCode(std::string presentation, byte code, ParamType param1) : AssemblyPresentation(presentation), MachineCode(code), Param1(param1), Param2(NONE) {}
  OpCode(std::string presentation, byte code) : AssemblyPresentation(presentation), MachineCode(code), Param1(NONE), Param2(NONE) {}
};

OpCode OpCodes[] = {

  // HLT
  OpCode("HLT", 0x00),

  // MOV
  OpCode("MOV", 0xC1, REGISTER, REGISTER),
  OpCode("MOV", 0xC2, REGISTER, ADDRESS),
  OpCode("MOV", 0xC3, REGISTER, CONSTANT),
  OpCode("MOV", 0xC4, ADDRESS, REGISTER),
  OpCode("MOV", 0xC5, ADDRESS, CONSTANT),

  // ADD/SUB
  OpCode("ADD", 0xC6, REGISTER, REGISTER),
  OpCode("ADD", 0xC7, REGISTER, ADDRESS),
  OpCode("ADD", 0xC8, REGISTER, CONSTANT),
  OpCode("SUB", 0xC9, REGISTER, REGISTER),
  OpCode("SUB", 0xCA, REGISTER, ADDRESS),
  OpCode("SUB", 0xCB, REGISTER, CONSTANT),

  // INC/DEC
  OpCode("INC", 0x8C, REGISTER),
  OpCode("DEC", 0x8D, REGISTER),

  // MUL/DIV
  OpCode("MUL", 0x8E, REGISTER),
  OpCode("MUL", 0x8F, ADDRESS),
  OpCode("MUL", 0x90, CONSTANT),
  OpCode("DIV", 0x91, REGISTER),
  OpCode("DIV", 0x92, ADDRESS),
  OpCode("DIV", 0x93, CONSTANT),

  // COMPARISON
  OpCode("CMP", 0xD4, REGISTER, REGISTER),
  OpCode("CMP", 0xD5, REGISTER, ADDRESS),
  OpCode("CMP", 0xD6, REGISTER, CONSTANT),

  // LOGICAL INSTRUCTIONS
  OpCode("AND", 0xD7, REGISTER, REGISTER),
  OpCode("AND", 0xD8, REGISTER, ADDRESS),
  OpCode("AND", 0xD9, REGISTER, CONSTANT),
  OpCode("OR",  0xDA, REGISTER, REGISTER),
  OpCode("OR",  0xDB, REGISTER, ADDRESS),
  OpCode("OR",  0xDC, REGISTER, CONSTANT),
  OpCode("XOR", 0xDD, REGISTER, REGISTER),
  OpCode("XOR", 0xDE, REGISTER, ADDRESS),
  OpCode("XOR", 0xDF, REGISTER, CONSTANT),

  // SHIFT INSTRUCTIONS
  OpCode("SHL", 0xE0, REGISTER, REGISTER),
  OpCode("SHL", 0xE1, REGISTER, ADDRESS),
  OpCode("SHL", 0xE2, REGISTER, CONSTANT),
  OpCode("SHR", 0xE3, REGISTER, REGISTER),
  OpCode("SHR", 0xE4, REGISTER, ADDRESS),
  OpCode("SHR", 0xE5, REGISTER, CONSTANT),

  // JUMPS
  OpCode("JMP",  0xA6, ADDRESS),
  OpCode("JC",   0xA7, ADDRESS),
  OpCode("JB",   0xA7, ADDRESS),
  OpCode("JNAE", 0xA7, ADDRESS),
  OpCode("JNC",  0xA8, ADDRESS),
  OpCode("JNB",  0xA8, ADDRESS),
  OpCode("JAE",  0xA8, ADDRESS),
  OpCode("JZ",   0xA9, ADDRESS),
  OpCode("JE",   0xA9, ADDRESS),
  OpCode("JNZ",  0xAA, ADDRESS),
  OpCode("JNE",  0xAA, ADDRESS),
  OpCode("JA",   0xAB, ADDRESS),
  OpCode("JNBE", 0xAB, ADDRESS),
  OpCode("JNA",  0xAC, ADDRESS),
  OpCode("JB",   0xAC, ADDRESS),

  // OTHER
  OpCode("CALL", 0xAD, ADDRESS),
  OpCode("RET",  0x6E),
  OpCode("PUSH", 0xAF, REGISTER),
  OpCode("PUSH", 0xB0, ADDRESS),
  OpCode("PUSH", 0xB1, CONSTANT),
  OpCode("POP",  0xB2, REGISTER),
};