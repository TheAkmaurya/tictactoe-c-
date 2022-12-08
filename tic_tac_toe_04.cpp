// now only one is left
// last one is based on 3 ways of scenario
// 1) p1 or p2 win
// 2) game playing still on the way
// 3) gamedraw

#include <iostream>
using namespace std;
int choice;
char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool tie;

void display_box()
{
  system("cls");
  cout << "\n\t\t\t\tT i c - T a c - T o e  C r o s s  G a m e" << endl;
  cout << "Player1[x]" << endl;
  cout << "Player2[o]" << endl;
  cout << "\t\t\t\t     |     |     " << endl;
  cout << "\t\t\t\t  " << game[0][0] << "  |  " << game[0][1] << "  |  " << game[0][2] << "  " << endl;
  cout << "\t\t\t\t_____|_____|_____" << endl;
  cout << "\t\t\t\t     |     |     " << endl;
  cout << "\t\t\t\t  " << game[1][0] << "  |  " << game[1][1] << "  |  " << game[1][2] << "  " << endl;
  cout << "\t\t\t\t_____|_____|_____" << endl;
  cout << "\t\t\t\t     |     |     " << endl;
  cout << "\t\t\t\t  " << game[2][0] << "  |  " << game[2][1] << "  |  " << game[2][2] << "  " << endl;
  cout << "\t\t\t\t     |     |     " << endl;
}

void player_turn()
{
  int row, column;
  if (turn == 'X')
  {
    cout << "Player1[x] turn: ";
  }
  if (turn == 'O')
  {
    cout << "Player2[o] turn: ";
  }
  cin >> choice;
  switch (choice)
  {
  case 1:
    row = 0;
    column = 0;
    break;
  case 2:
    row = 0;
    column = 1;
    break;
  case 3:
    row = 0;
    column = 2;
    break;
  case 4:
    row = 1;
    column = 0;
    break;
  case 5:
    row = 1;
    column = 1;
    break;
  case 6:
    row = 1;
    column = 2;
    break;
  case 7:
    row = 2;
    column = 0;
    break;
  case 8:
    row = 2;
    column = 1;
    break;
  case 9:
    row = 2;
    column = 2;
    break;

  default:
    cout << "Invalid Choice";
    break;
  }

  if (turn == 'X' && game[row][column] != 'X' && game[row][column] != 'O')
  {
    game[row][column] = 'X';
    turn = 'O';
  }
  else if (turn == 'O' && game[row][column] != 'X' && game[row][column] != 'O')
  {
    game[row][column] = 'O';
    turn = 'X';
  }
  else
  {
    cout << "You have already filled the BOX" << endl
         << "Please Choose Another Block!!" << endl;
    player_turn();
  }
}
bool gameover()
{
  for (int i = 0; i < 3; i++)
  {
    if (game[i][0]==game[i][1] && game[i][0]==game[i][2] || game[0][i]==game[1][i] && game[0][i]==game[2][i] )
    return false;

  }
  if(game[0][0]==game[1][1] && game[0][0]==game[2][2] || game[0][2]==game[1][1] && game[0][2]==game[2][0])
  {
    return false;
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if(game[i][j]!= 'X' && game[i][j]!= 'O' )
      {
        return true;
      }
    } 
  }
  tie=true;
  return false;
  
  
}

int main()
{
  while (gameover())
  {
    display_box();
    player_turn();
    display_box();
  }
  if (turn=='X' && tie==false)
  {
    cout<<"Player2[o] Wins !! Congratulation";
  }
  else if (turn=='O' && tie==false)
  {
    cout<<"Player1[o] Wins !! Congratulation";
  }
  else{
    cout<<"GAME TIE!";
  }
  
  return 0;
}