/*
Elijah Chan 9/8/2026
*/

#include <iostream>

using namespace std;

void printBoard(char** board, char* lett)
{
  cout << " 123" << endl;
  for(int i = 0; i < 3; i++) {
    char outl[4];
    outl[0] = lett[i];
    for(int j = 0; j < 3; j++) {
      outl[j + 1] = board[i][j];
    }
    cout << outl << endl;
  }
  
}

bool checkWin(char** board) {
  return false;
}


void place(char** board, char coord[2], bool player) {
  if(player) {
    board[coord[0]][coord[1]] = 'x';
  }
  else {
    board[coord[0]][coord[1]] = 'o';
  }
}

int main()
{
  char lett[3] = {'a', 'b', 'c'};
  char* lettptr = lett;
  char* board[3];
  char** boardptr = board;
  bool playing = true;
  char input[2];
  bool player = true;
  
  for(int i = 0; i < 3; i++) {
    char* b = new char[3];
    for(int j = 0; j < 3; j++) {
      b[j] = ' ';
    }
    board[i] = b;
  }

  printBoard(boardptr, lettptr);
  
  while(playing) {
    cout << "Enter a coordinate point: ";
    cin >> input;
    cout << input << endl;
    printBoard(boardptr, lettptr);
    playing = false;
  }
  
}
