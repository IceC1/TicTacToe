/*
Elijah Chan 9/8/2026
Runs a game of tictactoe between two players. The board is reset after one player wins and the score is tracked.
*/

#include <iostream>

using namespace std;

//Sets all the spaces in the board to a space character.
void clearBoard(char** board) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}
  
//Prints out the board and adds the abc and 123 indeces.
void printBoard(char** board)
{
  char lett[3] = {'a', 'b', 'c'};
  cout << " 123" << endl;
  for(int i = 0; i < 3; i++) {
    char outl[5];
    outl[0] = lett[i];
    for(int j = 0; j < 4; j++) {
      outl[1 + j] = board[i][j];
    }
    cout << outl << endl;
  }
}

//Checks if any one player wins when they make a move.
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

//Checks if the coordinate inputted is occupied and then checks for wins if the move is valid.
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
    cout << "Space is already occupied" << endl;
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

  //Initializes the 2d array.
  for(int i = 0; i < 3; i++) {
    char* b = new char[4];
    for(int j = 0; j < 3; j++) {
      b[j] = ' ';
    }
    b[3] = '\0';
    board[i] = b;
  }
  
  printBoard(boardptr);

  //Runs the playing loop.
  while(playing) {
 
    cout << "Enter a coordinate point(a1, b2, c3 etc.): ";
    cin >> input;
    
    //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    coords[1] = input[1] - '0' - 1;
    if((coords[1] >= 0) && (coords[1] <= 2)) { 
      if(input[0] == 'a') {
	coords[0] = 0;
      }
      else if(input[0] == 'b') {
	coords[0] = 1;
      }
      else if(input[0] == 'c') {
	coords[0] = 2;
      }
      else {
	cout << "Out of bounds" << endl;
	continue;
      }
    }
    else {
	cout << "Out of bounds" << endl;
	continue;
    }
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
