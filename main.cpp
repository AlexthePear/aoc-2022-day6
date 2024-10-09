#include <unordered_set>
#include <algorithm> // find
#include <vector>
#include <fstream> // ifstream
#include <iostream>


// Take 14 characters and insert them into a hash set, then get the size of it
int hash_set_simple(const std::string &input) {
  for (size_t i = 0; i <= input.size() - 14; ++i) {
    std::unordered_set<char> window(input.begin() + i, input.begin() + i + 14);
    if (window.size() == 14) {
      return i + 14;
    }
  }
  return -1;
}

// Insert characters into the hash set one at a time
int hash_set_faster(const std::string &input) {
  for (size_t i = 0; i <= input.size() - 14; ++i) {
    std::unordered_set<char> chars;
    for (size_t j = i; j < i + 14; ++j) {
      if (chars.count(input[j]) != 0) {
        break;
      }
      chars.insert(input[j]);
    }
    if (chars.size() == 14) {
      return i + 14;
    }
  }
  return -1;
}

// Use a vector (faster than hash map for small window sizes)
int faster_vector(const std::string &input) {
  for (size_t i = 0; i <= input.size() - 14; ++i) {
    std::vector<char> chars;
    chars.reserve(14);
    for (size_t j = i; j < i + 14; ++j) {
      if (std::find(chars.begin(), chars.end(), input[j]) != chars.end()) {
        break;
      }
      chars.push_back(input[j]);
    }
    if (chars.size() == 14) {
      return i + 14;
    }
  }
  return -1;
}

// Use an array (stack allocated, faster than vector)
int faster_array(const std::string &input) {
  for (size_t i = 0; i <= input.size() - 14; ++i) {
    char chars[14];
    bool unique = true;
    size_t arr_idx = 0;
    for (size_t j = 0; j < 14; ++j) {
      for (size_t k = 0; k < arr_idx; ++k) {
        if (chars[k] == input[i + j]) {
          unique = false;
          break;
        }
      }
      if (!unique) break;
      chars[arr_idx] = input[i + j];
      ++arr_idx;
    }
    if (unique) {
      return i + 14;
    }
  }
  return -1;
}

int main() {
  std::ifstream inputfile("input.txt");
  if (!inputfile.is_open()) {
    std::cerr << "Error opening the file!\n";
    return 1;
  }

  std::string line;
  std::getline(inputfile, line);

  std::cout << hash_set_simple(line) << "\n";
  std::cout << hash_set_faster(line) << "\n";
  std::cout << faster_vector(line) << "\n";
  std::cout << faster_array(line) << "\n";

  return 0;
}
