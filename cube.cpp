#include <iostream>
#include <string>

using namespace std;


#define BOARD_X	4
#define BOARD_Y	4

#define RED	"\033[1;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[1;37m"
#define END	"\033[0m"

#define P1	RED
#define P2	BLUE

struct board_s {
  int nums[BOARD_X][BOARD_Y];
  int player[BOARD_X][BOARD_Y];
} board;

// Test colors first:
void printColor(string str, string c) {
  cout << c;
  cout << str;
  cout << END;
}

void clearScr() {
  cout << "\033c";
}

void sleep(double sec) {
  string command = "sleep " + to_string(sec);
  // cout << command << endl;
  system (&command[0]);
}

void drawLine() {
  printColor("+", WHITE);
  for (int j = 0; j < BOARD_X; j++) {
    printColor("-+", WHITE);
  }
  // printColor('+', WHITE);
  std::cout << endl;
}

void reset() {
  for (int i = 0; i < BOARD_Y; i++) {
    for (int j = 0; j < BOARD_X; j++) {
      board.player[i][j] = 0;
      board.nums[i][j] = 1;
    }
  }
}

void printNums(int nums[BOARD_X], int player[BOARD_X]) {
  printColor("|", WHITE);
  for (int i = 0; i < BOARD_X; i++) {
    if (player[i] == 1) {
      printColor(to_string(nums[i]), P1);
    } else if (player[i] == -1) {
      printColor(to_string(nums[i]), P2);
    } else {
      printColor(to_string(nums[i]), WHITE);
    }
    printColor("|", WHITE);
  }
  std::cout << endl;
}
  
void drawBoard(int nums[BOARD_X][BOARD_Y], int player[BOARD_X][BOARD_Y]) {
  clearScr();
  std::cout << "\n\t";
  drawLine();
  for (int i = 0; i < BOARD_Y; i++) {
    std::cout << '\t';
    printNums(nums[i], player[i]);
    std::cout << '\t';
    drawLine();
  }
  std::cout << '\n';
  sleep(0.25);

}

void drawBoard() {
  clearScr();
  std::cout << "\n\t";
  drawLine();
  for (int i = 0; i < BOARD_Y; i++) {
    std::cout << "\t|";
    for (int j = 0; j < BOARD_X; j++) {
      std::cout << " |";
    }
    std::cout << "\n\t";
    drawLine();
  }
  std::cout << '\n';
  sleep(0.5);
}

int neighbors(int x, int y) {
  // Three cases:
  // 1. Corners
  // 2. Edges
  // 3. The rest
  if ( (x == 0 || x == BOARD_X-1) && (y == 0 || y == BOARD_Y-1) ) {
    return 2;
  } else if ( (x == 0 || x == BOARD_X-1) || (y == 0 || y == BOARD_Y-1) ) {
    return 3;
  } else {
    return 4;
  }
} 

bool updateNums(int turn) {
  bool repeat = false;
  for (int i = 0; i < BOARD_Y; i++) {
    for (int j = 0; j < BOARD_X; j++) {
      if (board.nums[j][i] > neighbors(j, i)) {
	repeat = true;
	board.nums[j][i] -= neighbors(j, i);
	// Update four corners:
	if (i - 1 >= 0){ board.nums[j][i-1]++; board.player[j][i-1] = turn; }
	if (j - 1 >= 0){ board.nums[j-1][i]++; board.player[j-1][i] = turn; }
	if (i + 1 < BOARD_Y){ board.nums[j][i+1]++; board.player[j][i+1] = turn; }
	if (j + 1 < BOARD_X){ board.nums[j+1][i]++; board.player[j+1][i] = turn; }
	drawBoard(board.nums, board.player);
      }
    }
  }
  return repeat;
}

bool victory() {
  int temp = board.player[0][0];
  for (int i = 0; i < BOARD_X; i++) {
    for (int j = 0; j < BOARD_Y; j++) {
      if (board.player[j][i] != temp || board.player[j][i] == 0) return false;
    }
  }
  return true;
}

int updateBoard(int X, int Y, int turn) {
  // Check if allowed (has to be own or neutral):
  if (turn == board.player[X][Y] || board.player[X][Y] == 0) {
    board.player[X][Y] = turn;
    board.nums[X][Y]++;
    while (!victory() && updateNums(turn)) {
      // drawBoard(board.nums, board.player);
    }
    return (turn == 1) ? -1 : 1;
  } else {
    return turn; 
  }
}

void init() {
  reset();
  drawBoard();
  std::cout << "Player 1 starts!";
}



void play() {
  int row, col;
  int turn = 1;
  bool done = false;
  
  while (!done) {
    drawBoard(board.nums, board.player);
    printColor("Please enter the coordinates (-1 -1 for exit): ", 
	       (turn == 1) ? RED : BLUE);
    std::cin >> col >> row;
    while (row < -1 || col < -1 || row >= BOARD_Y || col >= BOARD_X) {
      drawBoard(board.nums, board.player);
      printColor("Try again (-1 -1 for exit): ", 
	       (turn == 1) ? RED : BLUE);
      std::cin >> col >> row;
    }
    if (row == -1 || col == -1) return;

    turn = updateBoard(col, row, turn);
    done = victory();
  }

  std::cout << "CONGRATULATIONS ";
  if (board.player[0][0] == 1)
    printColor("RED ", RED);
  else if (board.player[0][0] == -1)
    printColor("BLUE ", BLUE);
  else
    printColor("???WTF??? ", CYAN);
  std::cout << "PLAYER!\n";
}

int main() {
  reset();
  init();
  play();
}
