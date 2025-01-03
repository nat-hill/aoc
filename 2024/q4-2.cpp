#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
vector<vector<char>> gmatrix;
int n;
int m;

bool check_mas(int i, int j) {
  bool mas1 = (gmatrix[i-1][j+1] == 'M' && gmatrix[i+1][j-1] == 'S') || (gmatrix[i-1][j+1] == 'S' && gmatrix[i+1][j-1] == 'M');

  bool mas2 = (gmatrix[i+1][j+1] == 'M' && gmatrix[i-1][j-1] == 'S') || (gmatrix[i+1][j+1] == 'S' && gmatrix[i-1][j-1] == 'M');

  return mas1 && mas2;
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
  int mas_found = 0;
  gmatrix = readMatrix("q4-input.txt");
  n = gmatrix.size();
  m = gmatrix[0].size();
  std::cout << "N:" << n << " M:" << m << "\n";

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (gmatrix[i][j] == 'A') {
        if (check_mas(i, j)) {
          mas_found += 1;
        }
      }
    }
  }
  std::cout << "Result: " << mas_found << "\n";
};
