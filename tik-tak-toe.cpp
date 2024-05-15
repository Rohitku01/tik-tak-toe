#include<iostream>
#include<stdlib.h>
using namespace std;
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int n;
string s1,s2;
//
void print()
{
    for(int i=0; i<9; i++)
    {
        if(i==1 || i==2 || i==4 || i==5 || i==7 || i==8)
        {
            cout<< " | ";
        }
        cout<<board[i];
        if(i==2 || i==5)
        {
            cout<<endl;
            cout<< "---------";
            cout<<endl;
        }
    }
}

void s1board_value()
{
    // if(s1!=" ")
    // {
        if(n==1 || n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9)
        {
            board[n-1]='X';
        }   
    // }
}

void s2board_value()
{
    if(n==1 || n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9)
    {
        board[n-1]='O';
    }   
}

void Firstplayer_move(string s1)
{
    cout<<endl;
    cout<<"Play Your Move "<<s1<<endl;
    cin>>n;
    cout<<endl;
}

void secondplayer_move(string s2)
{
    cout<<endl;
    cout<<"Play Your Move "<<s2<<endl;
    cin>>n;
    cout<<endl;
}

void space_check()
{
    if(board[n-1]!=' ')
    {
        cout<<"Already Taken!"<<endl<<"Choose Another Option"<<endl;
        cin>>n;
    }
}

void win_check()
{
    if(board[0]=='X' && board[1]=='X' && board[2]=='X' 
        || board[3]=='X' && board[4]=='X' && board[5]=='X'
        || board[6]=='X' && board[7]=='X' && board[8]=='X')
    {
        cout<<"\n"<<endl;
        cout<<s1<<" Wins The Game"<<endl;
        exit(0);
    }
    if(board[0]=='O' && board[1]=='O' && board[2]=='O' 
        || board[3]=='O' && board[4]=='O' && board[5]=='O'
        || board[6]=='O' && board[7]=='O' && board[8]=='O')
    {
        cout<<"\n"<<endl;
        cout<<s2<<" Wins The Game"<<endl;
        exit(0);
    }

    if(board[0]=='X' && board[3]=='X' && board[6]=='X' 
        || board[1]=='X' && board[4]=='X' && board[7]=='X'
        || board[2]=='X' && board[5]=='X' && board[8]=='X')
    {
        cout<<"\n"<<endl;
        cout<<s1<<"Wins The Game"<<endl;
        exit(0);
    }
    if(board[0]=='O' && board[3]=='O' && board[6]=='O' 
        || board[1]=='O' && board[4]=='O' && board[7]=='O'
        || board[2]=='O' && board[5]=='O' && board[8]=='O')
    {
        cout<<"\n"<<endl;
        cout<<s2<<"Wins The Game"<<endl;
        exit(0);
    }

    if(board[0]=='X' && board[4]=='X' && board[8]=='X' 
        || board[2]=='X' && board[4]=='X' && board[6]=='X')
    {
        cout<<"\n"<<endl;
        cout<<s1<<"Wins The Game"<<endl;
        exit(0);
    }
    if(board[0]=='O' && board[4]=='O' && board[8]=='O' 
        || board[2]=='O' && board[4]=='O' && board[6]=='O')
    {
        cout<<"\n"<<endl;
        cout<<s1<<"Wins The Game"<<endl;
        exit(0);
    }
}

int main()
{

    cout<<"________________________________________________\n\n\n";
    cout<<"             Welcome To The Game                \n\n\n";
    cout<<"________________________________________________\n\n\n";


    cout<<"Enter Player's Name:"<<endl;
    cout<<"X Player Name"<<endl;
    cin>>s1;
    cout<<"O Player Name"<<endl;
    cin>>s2;

    if(s1==s2)
    {
        cout<<"Name already Taken!"<<endl<<"Enter Different Name"<<endl;
        cin>>s2;
    }

    system("cls");

    print();
    cout<<endl;
   
    for(int i=1; i<=5; i++)
    {
       Firstplayer_move(s1);
        space_check();
        s1board_value();
        system("cls");
        print();
        win_check();
        cout<<endl;
        if(i==5)
        {
            cout<<endl;
            break;
        }
       secondplayer_move(s2);
        space_check();
        s2board_value();
        system("cls");
        print();
        win_check();
        cout<<endl;
    }
    cout<<"Match Draw"<<endl;

    return  0;
}