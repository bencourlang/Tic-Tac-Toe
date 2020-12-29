#include <iostream>
using namespace std;

char square[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int winsP1 = 0;
int winsP2 = 0;
int ties = 0;

int win(){
    if(square[0] == square[1] && square[1] == square[2] && square[1] != ' '){
        return 1;
    }
    else if(square[3] == square[4] && square[4] == square[5] && square[4] != ' '){
        return 1;
    }
    else if(square[6] == square[7] && square[7] == square[8] && square[7] != ' '){
        return 1;
    }
    else if(square[0] == square[3] && square[3] == square[6] && square[3] != ' '){
        return 1;
    }
    else if(square[1] == square[4] && square[4] == square[7] && square[4] != ' '){
        return 1;
    }
    else if(square[2] == square[5] && square[5] == square[8] && square[5] != ' '){
        return 1;
    }
    else if(square[0] == square[4] && square[4] == square[8] && square[4] != ' '){
        return 1;
    }
    else if(square[2] == square[4] && square[4] == square[6] && square[4] != ' '){
        return 1;
    }
    else if(square[0] != ' ' && square[1] != ' ' && square[2] != ' ' && square[3] != ' ' &&
            square[4] != ' ' && square[5] != ' ' && square[6] != ' ' && square[7] != ' ' &&
            square[8] != ' '){
                return 0;
            }
    else{
        return -1;
    }
}

void clearScreen(){
    for(int i = 0; i < 10; i++){
        cout << endl;
    }
}

bool check(bool &used){
    for(int i = 0; i < 9; i++){
        if(square[i] != ' '){

        }
    }
}

void intructions(){
    cout << "INSTRUCTIONS" << endl << endl;
    cout << "Take Turns entering the number of the space where you want to move" << endl;
    cout << "First to get three in a row wins" << endl << endl << endl;
}

void board(){
    clearScreen();
    intructions();
    cout << "TIC-TAC-TOE" << endl << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
    cout << "       |       |                      |       |       " << endl;
    cout << "   " << square[0] << "   |   " << square[1] << "   |   " << square[2];
    cout << "              1   |   2   |   3" << endl;
    cout << "_______|_______|_______        _______|_______|_______" << endl;
    cout << "       |       |                      |       |       " << endl;
    cout << "   " << square[3] << "   |   " << square[4] << "   |   " << square[5];
    cout << "              4   |   5   |   6" << endl;
    cout << "_______|_______|_______        _______|_______|_______" << endl;
    cout << "       |       |                      |       |       " << endl;
    cout << "   " << square[6] << "   |   " << square[7] << "   |   " << square[8];
    cout << "              7   |   8   |   9" << endl;
    cout << "       |       |                      |       |       " << endl;
    cout << endl;
}

void reset(){
    for(int i = 0; i < 9; i++){
        square[i] = ' ';
    }
}

int main(){
    int playAgain = 1;
    while(playAgain == 1){
        reset();
        int turn = 1;
        int choice;
        int winner = -1;
        char XorO;
        while(winner == -1){
            board();
            turn = (turn%2) ? 1:2;
            cout << "Player " << turn << ", enter a number: ";
            cin >> choice;
            XorO = (turn == 1) ? 'X':'O';

            if(choice == 1 && square[0] == ' '){
                square[0] = XorO;
            }
            else if(choice == 2 && square[1] == ' '){
                square[1] = XorO;
            }
            else if(choice == 3 && square[2] == ' '){
                square[2] = XorO;
            }
            else if(choice == 4 && square[3] == ' '){
                square[3] = XorO;
            }
            else if(choice == 5 && square[4] == ' '){
                square[4] = XorO;
            }
            else if(choice == 6 && square[5] == ' '){
                square[5] = XorO;
            }
            else if(choice == 7 && square[6] == ' '){
                square[6] = XorO;
            }
            else if(choice == 8 && square[7] == ' '){
                square[7] = XorO;
            }
            else if(choice == 9 && square[8] == ' '){
                square[8] = XorO;
            }
            else{
                turn--;
                cin.ignore();
                cout << "invalid move" << endl;
            }
            winner = win();
            turn++;
        }
        board();
        turn--;
        if(winner == 0){
            cout << "Tie Game" << endl;
            ties++;
        }
        else if(winner == 1){
            cout << "Player " << turn << " Wins" << endl;
            if(turn == 1){
                winsP1++;
            }
            else{
                winsP2++;
            }
        }
        cout << "\nWant to play again?" << endl;
        cout << "1. Play Again" << endl;
        cout << "2. Exit" << endl;
        bool checkPlayAgain = false;
        cin >> playAgain;
        while(checkPlayAgain == false){
            if(playAgain == 1 || playAgain == 2){
                checkPlayAgain = true;
            }
            else{
                cout << "Want to play again?" << endl;
                cout << "1. Play Again" << endl;
                cout << "2. Exit" << endl;
                cin >> playAgain;
            }
        }
    }
    cout << "\nPlayer 1 won " << winsP1;
    if(winsP1 == 1){
        cout << " time" << endl;
    }
    else{
        cout << " times" << endl;
    }
    cout << "Player 2 won " << winsP2;
    if(winsP2 == 1){
        cout << " time" << endl;
    }
    else{
        cout << " times" << endl;
    }
    cout << "There ";
    if(ties == 1){
        cout << "was " << ties << " tie\n" << endl;
    }
    else{
        cout << "were " << ties << " ties\n" << endl;
    }
}