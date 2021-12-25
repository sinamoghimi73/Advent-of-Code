#include <array>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, const char *argv[]) {
  std::ifstream file;
  std::string token{};
  std::array<int, 4> elem{0, 0, 0, 0};

  unsigned counter{};

  file.open("/input.txt");
  if (file.is_open()) {
    for (int i{}; i < 4; i++) {
      std::getline(file, token, '\n');
      elem[i] = std::stoi(token);
    }
    counter += (elem[3] > elem[0]) ? 1 : 0;
    while (std::getline(file, token, '\n')) {
      std::rotate(elem.begin(), elem.begin() + 1, elem.end());
      elem[3] = std::stoi(token);
      counter += (elem[3] > elem[0]) ? 1 : 0;
    }
    file.close();
  }

  std::cout << "Increase counts: " << counter << "\n";
  return 0;
}
