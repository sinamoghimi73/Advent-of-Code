#include <array>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {
  std::ifstream file;
  std::string token{};
  std::array<int, 3> val{0, 0, 0};

  file.open("/input.txt");
  if (file.is_open()) {
    while (std::getline(file, token, '\n')) {
      val[1] = stoi(token);
      val[2] += (val[1] > val[0]) ? 1 : 0;
      val[0] = val[1];
    }
    file.close();
  }
  val[2]--;

  std::cout << "Increase counts: " << val[2] << "\n";
  return 0;
}
