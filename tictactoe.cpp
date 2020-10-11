#include <iostream>

using namespace std;
int xwins = 0;
int owins = 0;
char board[3][3];
bool xturn[3][3];
bool otrun[3][3];
void boardreset();
void redraw();
bool xwin();
bool owin();

int main(){
  boardreset();
  redraw();
  return 0;
}

void boardreset(){//initializes the board
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      board [i][j] = ' ';
      bool xturn[i][j] = {false};
      bool oturn[i][j] = {false};
    }
  }
  board[1][0] = 'a';
  board[2][0] = 'b';
  board[3][0] = 'c';
  board[0][1] = '1';
  board[0][2] = '2';
  board[0][3] = '3';
  }

void redraw(){//redraws the board
  cout << "xwins: " << xwins << ", owins: " << owins << endl;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}
