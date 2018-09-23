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

  MainMemory.clear();

  std::istringstream lines(w_assemblyCode);
  std::string line;

  for(int i = 0; std::getline(lines, line); i++)
  {
    std::vector<byte> currentInstruction = ParseInstructionFromASM(line);
    if(currentInstruction.length() > 0)
    {
      MainMemory.insert(std::end(MainMemory), std::begin(currentInstruction), std::end(currentInstruction));
    }
  }

  return;
}

std::vector<byte>& RAM::ParseInstructionFromASM(std::string& w_line)
{

  MainMemory.clear();

  std::string cleared = w_line.substr(0, w_line.find(";"));
  std::stringstream ss_cmd(cleared);
  std::string command;
  std::string params;
  std::string param1, param2;
  std::getline(ss_cmd, command, ' ');
  std::getline(ss_cmd, params);
  std::stringstream ss_params(params);
  std::getline(ss_params, param1, ',');
  std::getline(ss_params, param2, ',');

  command.erase(std::remove(command.begin(), command.end(), ' '), command.end());
  param1.erase(std::remove(param1.begin(), param1.end(), ' '), param1.end());
  param2.erase(std::remove(param2.begin(), param2.end(), ' '), param2.end());

  /* In case we are dealing with a label */
  if(command.back() == ':')
  {
    labelMap[command.substr(0, command.size()-1)] = MainMemory.size();
    return vector<byte>();
  }

  /* SOMEHOW GET THE TYPE OF THE OPERATION, WHAT ARE THE PARAM TYPES? */
  for (auto it = OpCodes.begin(); it != std::prev(OpCodes.end()); it++)
  {

  }
}