#pragma once

#include <vector>
#include <map>
#include <string>

#include "Types.hpp"


class RAM
{
public:
  RAM();
  virtual ~RAM();

  void LoadMemoryFromBinary(std::string& w_fileName);

  void LoadMemoryFromAssemblyCode(std::string& w_assemblyCode);

private:
  std::vector<byte> MainMemory;
  bool verboseAvailable;
  std::map<byte, std::string> verboseMap;   // this is to keep track of every ASM presentation to the IP address
};