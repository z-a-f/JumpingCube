#include <iostream>

using namespace std;

// Test colors first:
void printColor(string str) {
  system("Color 1A");
  cout << str;
}

int main() {
  printColor("TEST\n");
}
