/*
Elijah Chan 9/8/2026
*/

#include <iostream>

using namespace std;

void clearBoard(char** board) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}
  

void printBoard(char** board)
{
  char lett[3] = {'a', 'b', 'c'};
  cout << " 123" << endl;
  for(int i = 0; i < 3; i++) {
    char outl[5];
    outl[0] = lett[i];
    for(int j = 0; j < 3; j++) {
      outl[1 + j] = board[i][j];
    }
    outl[5] = '\0';
    cout << outl << endl;
  }
}

//https://codehs.com/sandbox/pinksalmon0189/tictactoe
int checkWin(char** board, int coords[2]) {
  if(board[coords[0]][0] == board[coords[0]][1] && board[coords[0]][2] == board[coords[0]][1] ||
     board[0][coords[1]] == board[1][coords[1]] && board[2][coords[1]] == board[1][coords[1]]) {
    cout << "true" << endl;
    return 1;
  }
  else if(board[1][1] != ' ') {
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
       board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
      return 1;
    }
  }
  return 0;
}


int place(char** board, int coords[2], bool &player) {
  if(board[coords[0]][coords[1]] == ' ') {
    if(player) {
      board[coords[0]][coords[1]] = 'o';
    }
    else {
      board[coords[0]][coords[1]] = 'x';
    }
    player = !player;
    printBoard(board);
    }
  else {
    cout << "Invalid placement" << endl;
    return 0;
  }
  if(checkWin(board, coords)) {
    player = !player;
    return 1;
  }
  return 0;
}
int main()
{
  char* board[3];
  char** boardptr = board;
  bool playing = true;
  char input[3];
  int coords[2];
  bool player = false;
  int win = 0;
  int scores[2] = {0, 0};
  
  for(int i = 0; i < 3; i++) {
    char* b = new char[3];
    for(int j = 0; j < 3; j++) {
      b[j] = ' ';
    }
    board[i] = b;
  }
  
  printBoard(boardptr);
  
  while(playing) {
 
    cout << "Enter a coordinate point: ";
    cin >> input;
    
    if(input[0] == 'a') {
      coords[0] = 0;
    }
    else if(input[0] == 'b') {
      coords[0] = 1;
    }
    else if(input[0] == 'c') {
      coords[0] = 2;
    }
    //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    coords[1] = input[1] - '0' - 1;
    win = place(boardptr, coords, player);
    if(win) {
      cout << "Player " << player + 1 << " wins!" << endl;
      scores[player]++;
      cout << "Player 1: " << scores[0] << "\nPlayer 2: " << scores[1] << endl;
      clearBoard(boardptr);
      player = false;
      printBoard(boardptr);
    }
  }
  
}
