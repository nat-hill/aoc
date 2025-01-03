#include <iostream>
// #include <sstream>
#include <string>
#include <fstream>
#include <regex>

int main() {
  std::string line;
  std::ifstream inputFile("q3-input.txt");
  int sumtotal;
  int op1;
  int op2;
  bool mul_on = true;
  std::regex split_num_regex("mul\\((\\d+),(\\d+)\\)|do(n't)*\\(\\)");// mul(x,y) || do() || don't()

  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      // std::cout << line << '\n';
      auto begin = std::sregex_iterator(line.begin(), line.end(), split_num_regex);
      auto end = std::sregex_iterator();
      for (std::sregex_iterator i = begin; i != end; i++) {
        std::smatch match = *i;
        bool is_not_mult = match[1].str() == "";
        if (is_not_mult) {
          if (match[0].str() == "do()") {
            mul_on = true;
          } else {
            mul_on = false;
          }
        } else {
          op1 = std::stoi(match[1].str());
          op2 = std::stoi(match[2].str());
          if (mul_on) {
            sumtotal += (op1 * op2);
          }
        }
      }
    }

  }
  std::cout << sumtotal;
}
