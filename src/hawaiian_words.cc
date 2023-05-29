#include <iostream>
#include <string>

#include "functions.hpp"
using namespace std;
int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./bin/exec word" << std::endl;
    return 1;
  }
  std::string in = argv[1];
  in = phonetics(in);
  if (!in.empty()) {
    return 0;
  }
  cout << in << std::endl;
}