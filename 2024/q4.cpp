// Approach: Brute force DFS out from every X. 
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
const std::string target = "XMAS";
vector<vector<char>> gmatrix;
int n;
int m;

/*
 * Starting at (i, j), paths outwards in direction dir
 * Returns true if path is "XMAS" and does not go out of bounds.
 */
bool path_outwards(int i, int j, vector<int> dir, int len) {
  // std::cout << "Path " << i << " " << j << "\n";
  if (i >= n || j >= m || i < 0 || j < 0) {
    return false;
  } else if (gmatrix[i][j] != target[len]) {
    return false;
  } else {
    if (len >= 3) {
      // std::cout << "MATCH!: " << i << " " << j << " " << dir[0] << dir[1] << "\n";
      return true;
    } else {
      return path_outwards(i + dir[0], j + dir[1], dir, len + 1);
    }
  }
}

vector<vector<char>> readMatrix(std::string filename) {
  std::string line;
  vector<vector<char>> rmatrix;
  std::ifstream inputFile(filename);

  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      vector<char> row;
      for (char c : line) {
        row.push_back(c);
      }
      rmatrix.push_back(row);
    }
  }

  inputFile.close();
  return rmatrix;
}

int main() {
  // Read the input into a matrix.
  // int n; // Num columns;
  // int m; // Num rows
  int correct_paths = 0;
  gmatrix = readMatrix("q4-input.txt");
  n = gmatrix.size();
  m = gmatrix[0].size();
  std::cout << "N:" << n << " M:" << m << "\n";

  vector<vector<int>> directions {{0, 1}, {1,1}, {1,0}, {1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // std::cout << "Proc " << i << " " << j << "\n";
      if (gmatrix[i][j] == 'X') {
        for (vector<int> go_dir : directions) {
          if (path_outwards(i, j, go_dir, 0)) {
            correct_paths += 1;
          }
        }
      }
    }
  }
  std::cout << "Result: " << correct_paths << "\n";
};
