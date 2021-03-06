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

enum class State {kEmpty, kObstacle, kClosed};

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

int Heuristic(int x1, int x2, int y1, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid) {
	openlist.push_back(vector<int>{x, y, g, h});
	grid[x][y] = State::kClosed;
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
	cout << "No path found!" << "\n";
  	return std::vector<vector<State>> {};
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
    
  int init[2]{0, 0};
  int goal[2]{4, 5};
  auto board = ReadBoardFile("boardFile");

  auto solution = Search(board, init, goal);
  PrintBoard(solution);
}