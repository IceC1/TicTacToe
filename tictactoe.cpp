/*
Elijah Chan 9/8/2026
*/

#include <iostream>

using namespace std;

void clearBoard(char** board) {
  return;
}
  

void printBoard(char** board, char* lett)
{
  cout << " 123" << endl;
  for(int i = 0; i < 3; i++) {
    char outl[4];
    outl[0] = lett[i];
    for(int j = 0; j < 3; j++) {
      outl[1 + j] = board[i][j];
    }
    cout << outl << endl;
  }
  
}

int checkWin(char** board) {
  return 0;
}


int place(char** board, int coords[2], bool* playerptr) {
  bool player = playerptr[0];
  if(board[coords[0]][coords[1]] == ' ') {
    if(player) {
      board[coords[0]][coords[1]] = 'x';
    }
    else {
      board[coords[0]][coords[1]] = 'o';
    }
    player = !player;
    }
  else {
    cout << "Invalid placement";
  }
  int win = checkWin(board);
  if(checkWin(board)) {
    return 0;
  }
  return 0;
}
int main()
{
  char lett[3] = {'a', 'b', 'c'};
  char* lettptr = lett;
  char* board[3];
  char** boardptr = board;
  bool playing = true;
  char input[2];
  int coords[2];
  bool player = true;
  int win = 0;
  
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
    cin.get(input, 2);
    cin.get();
    cout << input;
    
    if(input[0] == 'a') {
      coords[0] = 0;
    }
    else if(input[0] == 'b') {
      coords[0] = 1;
    }
    else if(input[0] == 'c') {
      coords[0] = 2;
    }
    coords[1] = input[1];
    cout << coords[0] << coords[1] << endl;
    win = place(boardptr, coords, &player);
    printBoard(boardptr, lettptr);
    playing = false;
  }
  
}
