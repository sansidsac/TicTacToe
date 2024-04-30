#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char board[3][3];

void showboard(){
    cout<<"\n";
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2];
    cout<<"\n-----------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2];
    cout<<"\n-----------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2];
}

void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}

int checkwin(char player,int mode){
    int win=0;
    for(int i=0;i<3;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            win=1;
            break;
        }
    }
    for(int i=0;i<3;i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            win=1;
            break;
        }
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player){
        win=1;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player){
        win=1;
    }
    if(win==1){
        if(mode==1){
            cout<<"\nPlayer "<<player<<" WON the match";
        }
        else if(mode==2){
            cout<<"\nPlayer WON the match";
        }
        else if(mode==3){
            cout<<"\nComputer WON the match";
        }
        return 1;
    }
    int track=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='X' || board[i][j]=='O'){
                track++;
            }
        }
    }
    if(track==9){
        cout<<"\nDraw";
        return 1;
    }
    return 0;
}

void playervsplayer(){
    resetboard();
    int gameover=0,check=0;
    showboard();
    while(gameover==0){
        while(true){
            int col,row;
            cout<<"\nPlayer X turn (row(1-3),col(1-3)): ";
            cin>>row>>col;
            if(board[row-1][col-1]==' '){
                board[row-1][col-1]='X';
                break;
            }
            else{
                cout<<"\nInvalid move";
            }
        }
        showboard();
        check=checkwin('X',1);
        if(check==1){
            gameover=1;
            break;
        }
        while(true){
            int col,row;
            cout<<"\nPlayer O turn (row(1-3),col(1-3)): ";
            cin>>row>>col;
            if(board[row-1][col-1]==' '){
                board[row-1][col-1]='O';
                break;
            }
            else{
                cout<<"\nInvalid move";
            }
        }
        showboard();
        check=checkwin('O',1);
        if(check==1){
            gameover=1;
            break;
        }
    }
}

void playervscomputer(){
    resetboard();
    int gameover=0,check=0;
    int n,c=8;
    time_t t;
    srand((unsigned) time(&t));
    showboard();
    while(gameover==0){
        while(true){
            int col,row;
            cout<<"\nPlayer's turn (row(1-3),col(1-3)): ";
            cin>>row>>col;
            if(board[row-1][col-1]==' '){
                board[row-1][col-1]='X';
                break;
            }
            else{
                cout<<"\nInvalid move";
            }
        }
        showboard();
        check=checkwin('X',2);
        if(check==1){
            gameover=1;
            break;
        }
        cout<<"\nCompter's turn: ";
        n=rand()%c+1;
        int k=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    k++;
                }
                if(k==n && board[i][j]==' '){
                    board[i][j]='O';
                }
            }
        }
        c-=2;
        showboard();
        check=checkwin('O',3);
        if(check==1){
            gameover=1;
            break;
        }
    }
}

int main(){
    int choice=1,ch;
    while(choice==1){
        int op;
        cout<<"1. Player vs Player\n2. Player vs Computer\nEnter choice: ";
        cin>>op;
        if(op==1){
            playervsplayer();
        }
        else if(op==2){
            playervscomputer();
        }
        else{
            cout<<"\nEnter valid choice";
        }
        cout<<"\nDo you wish to continue (1.Yes/2.No): ";
        cin>>choice;
    }
    return 0;
}