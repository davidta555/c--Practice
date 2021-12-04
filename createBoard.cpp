#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::ifstream;
using std::cout;
using std::string;
using std::vector;

void ReadBoardFile(string path) {
	ifstream my_file (path);
  	if (my_file) {
        string line;
        while (getline(my_file, line)) {
            cout << line << "\n";
      }
   }
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
    
    ReadBoardFile("board");
    // PrintBoard(board);
}