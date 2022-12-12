#include<iostream>
#include<string>
using namespace std;
string p1, p2;
char turn = 'x';
int choice; 
int row, column;
bool draw = false;
char num[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void player_turn(){  
        if (turn == 'x')
    {
    cout<<"\n"<<p1<<"'s turn [x]\n";
    }
if (turn == 'o')
    {
    cout<<"\n"<<p2<<"'s turn [o]\n";
    }
cin>>choice;
        switch (choice)
        {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: 
             cout<<"INVALID TRY AGAIN"<<endl;
            break;
        }
        if (turn == 'x' && num[row][column] != 'x' && num[row][column] != 'o')
        {
            num[row][column] = 'x';
            turn = 'o';
        }
        else if (turn == 'o' && num[row][column] != 'x' && num[row][column] != 'o')
        {
            num[row][column] = 'o';
            turn = 'x';
        }
        else
        {
            cout<<"ALREADY FILLED!!\n   PLEASE TRY AGAIN!!!\n\n";
            player_turn();
        }        
    
    }

void input_data(){
    cout<<"         \n";
    cout<<"-------------TIC TAC TOE--------------\n";
    cout<<"         \n";
    cout<<"player 1 [x] \nplayer 2 [o]\n";
    cout<<"Enter player 1 name\n";
    cin>>p1;
    cout<<"Enter player 2 name\n";
    cin>>p2;
}

void display_tic(){
    cout<<"         \n";
    cout<<"         \n";
    cout<<"          |            |           \n";
    cout<<"    "<<num[0][0]<<"     |     "<<num[0][1]<<"      |    "<<num[0][2]<<"      \n";
    cout<<"----------|------------|-----------\n";
    cout<<"          |            |           \n";
    cout<<"    "<<num[1][0]<<"     |     "<<num[1][1]<<"      |    "<<num[1][2]<<"      \n";
    cout<<"----------|------------|-----------\n";
    cout<<"          |            |           \n";
    cout<<"    "<<num[2][0]<<"     |     "<<num[2][1]<<"      |    "<<num[2][2]<<"      \n";
    cout<<"         \n";
}

bool game_over(){
    for (int i = 0; i < 3 ; i++)
    {
        if (num[0][i] == num[i][1] && num[0][i] == num[i][2] || num[i][0] == num[1][i] && num[i][0] == num[2][i] || num[0][0] == num[1][1] && num[0][0]==num[2][2] || num[0][2]==num[1][1] && num[0][2]==num[2][0])
        {
            return false;
        }
        
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (num[j][k] != 'x' && num[j][k] != 'o')
            {
                return true;
            }
            
        }
        
    }
    draw = true;
    return false;
}
main(){
    input_data();
    while (game_over())
    {
    display_tic();
    player_turn();
    game_over();
    display_tic();
    }
if (turn == 'o' && draw == false)
{
    cout<<"\n"<<p1<<" won the game..... CONGRATULATIONS....!!!!!!!!\n";
}
else if (turn == 'x' && draw == false)
{
    cout<<"\n"<<p2<<" won the game..... CONGRATULATIONS....!!!!!!!!\n";
}
else
cout<<"GAME DRAW!!!\n";
}
