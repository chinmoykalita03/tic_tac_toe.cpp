//TIC TAC TOE in C++

#include<iostream>
#include<ctime>
using namespace std;

void createTable(char *spaces);
void playerMove(char *spaces,char player);
void computerMove(char *spaces,char computer);
bool winner(char *spaces,char player,char computer);
bool tie(char *spaces);

int main(){
  char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
  char player ='X';
  char computer ='O';
  bool running = true;

  createTable(spaces);
  while(running){
    playerMove(spaces,player);
    createTable(spaces);
    if(winner(spaces,player,computer)){
      running=false;
      break;
    }
    else if(tie(spaces)){
      running = false;
      break;
    }

    computerMove(spaces,computer);
    createTable(spaces);
    if(winner(spaces,player,computer)){
      running=false;
      break;
    }
     else if(tie(spaces)){
      running = false;
      break;
    }
  }
  return 0;
}

void createTable(char *spaces){
  cout<<"     |     |     "<<endl;
  cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
  cout<<"_____|_____|_____"<<endl;
  cout<<"     |     |     "<<endl;
  cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
  cout<<"     |     |     "<<endl;
  cout<<endl;

}
void playerMove(char *spaces,char player){
  int number;
  do{
    cout<<"Select the number(1-9) to place your move: ";
    cin>>number;
    number--;
    if(spaces[number]==' '){
      spaces[number]= player;
      break;
    }

  }while(number<0 || number>8);
}
void computerMove(char *spaces,char computer){
  int number;
  srand(time(NULL));
  while(true){
    number = rand()%9;
    if(spaces[number]==' '){
      spaces[number]=computer;
      break;
    }
  }
}

// 0   1   2
// 3   4   5 
// 6   7   8
bool winner(char *spaces,char player,char computer){
  if(spaces[0]!=' '  && spaces[0]== spaces[1]  && spaces[1]==spaces[2]){
    spaces[0]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[3]!=' '  && spaces[3]== spaces[4]  && spaces[4]==spaces[5]){
    spaces[3]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[6]!=' '  && spaces[6]== spaces[7]  && spaces[7]==spaces[8]){
    spaces[6]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[0]!=' '  && spaces[0]== spaces[3]  && spaces[3]==spaces[6]){
    spaces[0]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[1]!=' '  && spaces[1]== spaces[4]  && spaces[4]==spaces[7]){
    spaces[1]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[2]!=' '  && spaces[2]== spaces[5]  && spaces[5]==spaces[8]){
    spaces[2]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[0]!=' '  && spaces[0]== spaces[4]  && spaces[4]==spaces[8]){
    spaces[0]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else if(spaces[2]!=' '  && spaces[2]== spaces[4]  && spaces[4]==spaces[6]){
    spaces[2]==player ? cout<<"You Won!"<<endl : cout<<"You Lose"<<endl;
  }
  else{
    return false;
  }
  return true;
}
bool tie(char *spaces){
  for(int i=0;i<9;i++){
    if(spaces[i]==' '){
      return false;
    }
    }
    cout<<"Game is tie"<<endl;
    return true;
  }
