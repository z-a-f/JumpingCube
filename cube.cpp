#include <iostream>

using namespace std;

// Test colors first:
void printColor(string str) {
  //   system("bash");
  cout << str;
}

int main() {
  printColor("\033[1;31mTEST\n");
}
