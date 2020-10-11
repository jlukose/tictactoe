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
}

void redraw(){//redraws the board
  int a = 97;
  cout << "xwins: " << xwins << ", owins: " << owins << endl;
  cout << " 123" << endl;
  for (int i = 0; i < 3; i++){
    char w = static_cast<char>(a + i);
    cout << w;
    for (int j = 0; j < 3; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}
