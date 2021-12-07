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

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
  istringstream my_stream(line);
  
  char c;
  int n;
  vector<State> row;
  
  while (my_stream >> n >> c) {
    if (n == 0)
    {
      row.push_back(State::kEmpty);
    } else {
      row.push_back(State::kObstacle);
    }
    
  }
  return row;
}

vector<vector<State>> ReadBoardFile(string path) {
    ifstream my_file (path);
    vector<vector<State>> board{};

  	if (my_file) {
        string line;
        while (getline(my_file, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
   }
   return board;
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
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