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
  OpCode("HLT", 0x40),

  // MOV
  OpCode("MOV", 0xC1, REGISTER, REGISTER),
  OpCode("MOV", 0xC2, REGISTER, ADDRESS),
  OpCode("MOV", 0xC3, REGISTER, CONSTANT),
  OpCode("MOV", 0xC4, ADDRESS, REGISTER),
  OpCode("MOV", 0xC5, ADDRESS, CONSTANT),

  // ADD/SUB
};