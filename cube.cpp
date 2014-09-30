#include <iostream>
#include <string>

using namespace std;


#define BOARD_X	5
#define BOARD_Y	5

#define RED	"\033[1;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[0;37m"
#define END	"\033[0m"

#define P1	RED
#define P2	BLUE


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
  
void drawBoard() {
  clearScr();
  drawLine();
  int nums[BOARD_X] = {1, 2, 3, 4, 5};
  int player[BOARD_X] = {1, -1, 0, 1, -1};
  printNums(nums, player);
  drawLine();
  printNums(nums, player);
  drawLine();
  printNums(nums, player);
  drawLine();
  printNums(nums, player);
  drawLine();
  printNums(nums, player);
  drawLine();
}


int main() {
  drawBoard();
  sleep(1);
  drawBoard();
}
