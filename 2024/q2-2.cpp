#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define NONE 0
#define INCREASING 1
#define DECREASING 2

using std::string, std::cout, std::ifstream;

int is_safe_line(string line) {
    std::istringstream iss(line);
    std::vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }
    
    // Try each pattern (increasing/decreasing)
    for (int pattern : {INCREASING, DECREASING}) {
        // Try each position as the potential "problem" number to skip
        for (int skip_pos = -1; skip_pos < (int)nums.size(); skip_pos++) {
            bool valid = true;
            int prev = -1;
            
            // Check the sequence skipping the problem position
            for (int i = 0; i < nums.size(); i++) {
                if (i == skip_pos) continue;
                
                if (prev != -1) {
                    // Check pattern
                    if (pattern == INCREASING && prev >= nums[i]) {
                        valid = false;
                        break;
                    }
                    if (pattern == DECREASING && prev <= nums[i]) {
                        valid = false;
                        break;
                    }
                    // Check difference
                    int diff = abs(prev - nums[i]);
                    if (diff < 1 || diff > 3) {
                        valid = false;
                        break;
                    }
                }
                prev = nums[i];
            }
            
            if (valid) return 1; // Found a valid sequence by skipping at most one number
        }
    }
    
    return 2; // No valid sequence found even with one skip
}


int main() {
  ifstream inputFile("q2-input.txt");
  string line;
  int safe_count;

  if (inputFile.is_open()) {

    while (std::getline(inputFile, line)) {
      if (is_safe_line(line) <= 1) {
        // cout << "SAFE\n";
        safe_count += 1;
      } else {
        // cout << "NOT SAFE\n";
      }
    }
  }

  cout << safe_count << "\n"; // 409 too low.

  inputFile.close();
  return 0;

}

