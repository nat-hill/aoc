#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#define NONE 0
#define INCREASING 1
#define DECREASING 2

using std::string, std::cout, std::ifstream;

int main() {
  ifstream inputFile("q2-input.txt");
  string line;
  int prev;
  int curr;
  int safe_count;
  int pattern_type;
  bool safe;

  if (inputFile.is_open()) {

    while (std::getline(inputFile, line)) {
      std::istringstream iss(line);
      // cout << line << "\n";
      prev = -1;
      safe = true;
      pattern_type = NONE;

      // Safe if A) Levels all increasing, B) levels all decreasing, and C) adjacent levels can differ by at least one and at most 3
      while (iss >> curr) {


        if (pattern_type == NONE && prev != -1) {
          // Set pattern type to increasing or decreasing
          pattern_type = prev > curr ? DECREASING : INCREASING;
        }

        if (pattern_type == INCREASING) {
          if (prev >= curr) {
            safe = false;
          }
        }

        if (pattern_type == DECREASING) {
          if (prev <= curr) {
            safe = false;
          }
        }
        
        int diff = abs(prev - curr);
        if ( prev != -1 && (diff < 1 || diff > 3)) {
          safe = false;
        }

        if (!safe) {
          break;
        } 

        prev = curr;
      }

      if (safe) {
        safe_count += 1;
        // cout << "Safe Lines: " << safe_count << "\n";
      }


    }
  }

  cout << safe_count << "\n";

  inputFile.close();
  return 0;

}
