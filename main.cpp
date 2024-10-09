#include <iostream>
#include <fstream> // ifstream
#include <unordered_set>

int hash_set_solution(const std::string &input) {
  for (size_t i = 0; i <= input.size() - 14; ++i) {
    std::unordered_set<char> window(input.begin() + i, input.begin() + i + 14);
    if (window.size() == 14) {
      return i + 14;
    }
  }
  return -1;
}

int vector_soltution(const std::string &line) {
  return 0;
}

int main() {
  std::ifstream inputfile("input.txt");
  if (!inputfile.is_open()) {
    std::cerr << "Error opening the file!\n";
    return 1;
  }

  std::string line;
  std::getline(inputfile, line);

  std::cout << hash_set_solution(line) << "\n";

  return 0;
}
