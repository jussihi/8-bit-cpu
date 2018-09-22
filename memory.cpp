#include <iostream>
#include "memory.hpp"

RAM::RAM()
{
  verboseAvailable = false;
  std::cout << OpCodes[0].AssemblyPresentation << std::endl;
}

RAM::~RAM()
{

}

void RAM::LoadMemoryFromBinary(std::string& w_fileName)
{
  return;
}

void RAM::LoadMemoryFromAssemblyCode(std::string& w_assemblyCode)
{
  verboseAvailable = true;
  return;
}