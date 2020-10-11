#include <iostream>
#include <cstring>
//tictactoe by Joshua Lukose - game of tictactoe played between 2 people
using namespace std;
//initializing methods and variables
int xwins = 0;
int owins = 0;
char board[3][3];
bool xturn[3][3];
bool otrun[3][3];
void boardreset();
void redraw();
bool xwin();
bool owin();
void checkwins();
bool xmove;
void move();
bool haswon;
bool playing = true;
char input[2];
void ask();

int main(){
  while (playing == true){
    cout << endl << "Welcome to tictactoe, players take turns placing x and o where x goes first. Please specify your spot by entering the letter and number (example: b2)." << endl;
    boardreset();
    redraw();
    while(haswon == false){
      move();
      redraw();
      checkwins();
    }
    ask();
  }
  return 0;
}

void boardreset(){//initializes the board
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      board[i][j] = ' ';
      bool xturn[i][j] = {false};
      bool oturn[i][j] = {false};
    }
  }
  xmove = true;
  haswon = false;
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

void move(){//executes a player move
  cin.get(input, 2);
  int r = 0;
  int c = 0;
  cout << input[0] << input[1] << endl;
  //if (xturn[r][c] = false && oturn[r][c] = false){ 
  //  if (xmove = true){
  //    board[r][c] = 'X';
  //    xturn[r][c] = true;
  //    xmove = false;
  //  }
  //  if (xmove = false){
  //    board[r][c] = 'O';
  //    oturn[r][c] = true;
  //    xmove = true;
  //  }
  //}
  //else{
  //  cout << "please enter a valid empty space";
  //}
  haswon = true;
  return;
}

void checkwins(){//checks for a win or draw
  
  return;
}

void ask(){//asks if the players want to play again
  cout << "would you like to play again? (y/n)";
  char answer = '\0';
  answer = cin.get(answer);
  if (answer != 'y'){
    playing = false;
    return;
  }
}
