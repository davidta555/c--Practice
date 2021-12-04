#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line) {
  istringstream my_stream(line);
  
  char c;
  int n;
  vector<int> row;
  
  while (my_stream >> n >> c) {
    row.push_back(n);
  }
  return row;
}

vector<vector<int>> ReadBoardFile(string path) {
    ifstream my_file (path);
    vector<vector<int>> board{};

  	if (my_file) {
        string line;
        while (getline(my_file, line)) {
            vector<int> row = ParseLine(line);
            board.push_back(row);
        }
   }
   return board;
}


void PrintBoard(const vector<vector<int>> b) {
  	for (auto v : b) {
        for (int a : v) {
		    cout << a;
        }
        cout << "\n";
    }
}

int main() {
    // vector<vector<int>> board {
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 1, 0}
    // };
    
    auto board = ReadBoardFile("boardFile");
    PrintBoard(board);
}