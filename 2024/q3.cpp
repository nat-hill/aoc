// xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
// Make Regex to match mul(x,y) ONLY and sum the results.
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
  // std::regex mult_regex("mul\\([0-9]+,[0-9]+\\)");
  // Yo Dawg I Heard You Like Regex So I Made Regex For Your Regex
  std::regex split_num_regex("mul\\((\\d+),(\\d+)\\)");

  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      // std::cout << line << '\n';
      auto begin = std::sregex_iterator(line.begin(), line.end(), split_num_regex);
      auto end = std::sregex_iterator();
      for (std::sregex_iterator i = begin; i != end; i++) {
        std::smatch match = *i;
        // std::cout << match.str() << '\n';
        op1 = std::stoi(match[1].str());
        op2 = std::stoi(match[2].str());
        sumtotal += (op1 * op2);
      }
    }

  }
  std::cout << sumtotal;
}
