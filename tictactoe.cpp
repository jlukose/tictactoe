#include <iostream>
#include <cstring>
//tictactoe by Joshua Lukose - game of tictactoe played between 2 people
using namespace std;
//initializing methods and variables
int xwins = 0;
int owins = 0;
char board[3][3];
int boardid[3][3];
int turnid = 1;
void boardreset();
void redraw();
bool xwin();
bool owin();
bool checkwins(int turnid);
bool checktie();
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
      if (xmove == true){
	xmove = false;
	turnid = 2;
      }
      else {
	xmove = true;
	turnid = 1;
      }
    }
    if (turnid == 1){
      turnid = 2;
    }
    else {
      turnid = 1;
    }
    if (checkwins(turnid) == true) {
      if (turnid == 2){
	owins++;
	cout << "Player O has won." << endl;
      }
      else {
	xwins++;
	cout << "Player X has won." << endl;
      }
    }
    ask();
  }
  return 0;
}

void boardreset(){//initializes the board
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      board[i][j] = ' ';
      boardid[i][j] = 0;
    }
  }
  xmove = true;
  haswon = false;
}

void redraw(){//redraws the board
  int a = 97;
  cout << endl << "Xwins: " << xwins << ", Owins: " << owins << endl;
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
  bool hasmoved = false;
  while (hasmoved == false){
    cin >> input[0] >> input[1];
    int r = static_cast<int>(input[0]) - 97;
    int c = static_cast<int>(input[1]) - 49;
    if (boardid[r][c] == 0 && r < 3 && c < 3){ 
      if (xmove == true){
	board[r][c] = 'X';
	boardid[r][c] = 1;
	hasmoved = true;
      }
      if (xmove == false){
	board[r][c] = 'O';
	boardid[r][c] = 2;
	hasmoved = true;
      }
    }
    else{
      cout << "please enter a valid empty space" << endl;
    }
  }
  redraw();
  if (checkwins(turnid) == true || checktie() == true){
    haswon = true;
  }
  return;
}

bool checkwins(int player){//checks for a win or draw
  for (int i = 0; i < 3; i++){//checks horizontal wins
    int total = 0;
    for (int j = 0; j < 3; j++){
      if (boardid[i][j] == turnid){
	total++;
      }
    }
    if (total == 3){
      return true;
    }
  }

  for (int i = 0; i < 3; i++){//checks vertical wins
    int total = 0;
    for (int j = 0; j < 3; j++){
      if (boardid[j][i] == turnid){
	total++;
      }
    }
    if (total == 3){
      return true;
    }
  }

  if (boardid[0][0] == turnid && boardid[1][1] == turnid && boardid[2][2] ==  turnid){//checks diagonal win
    return true;
  }

  if (boardid[2][0] == turnid && boardid[1][1] == turnid && boardid[0][2] == turnid){//checks diagonal win
    return true;
  }
  
  return false;
}

bool checktie(){//checks for tie by seeing if there are no blank spaces
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (boardid[i][j] == 0){
	return false;
      }
    }
  }
  cout << "It's a tie!" << endl;
  return true;
}

void ask(){//asks if the players want to play again
  cout << "would you like to play again? (y/n)";
  char answer[1];
  cin >> answer[1];
  if (answer[1] == 'y'){
    playing = true;
  }
  else{
    playing = false;
  }
}
