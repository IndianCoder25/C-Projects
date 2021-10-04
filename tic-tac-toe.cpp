#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

char board[3][3];
char player1_choice;
char player2_choice;
char player1_name[20];
char player2_name[20];
int currentPlayer; // 0 means player1 and 1 means player2

void initializeBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    cout<<endl;
    printf("\n %c | %c | %c\n",board[0][0],board[0][1],board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",board[1][0],board[1][1],board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",board[2][0],board[2][1],board[2][2]);
    printf("\n%s => %c",player1_name,player1_choice);
    printf("\n%s => %c\n\n",player2_name,player2_choice);
}

void changeCurrentplayer(){
    if(currentPlayer == 0){
        currentPlayer=1;
    }else{
        currentPlayer=0;
    }
}

void fillEntry(int index, char sign,char *name){
    if(index == 1){
        board[0][0] = sign;
        changeCurrentplayer();
    }else if(index == 2){
        board[0][1] = sign;
        changeCurrentplayer();
    }else if(index == 3){
        board[0][2] = sign;
        changeCurrentplayer();
    }else if(index == 4){
        board[1][0] = sign;
        changeCurrentplayer();
    }else if(index == 5){
        board[1][1] = sign;
        changeCurrentplayer();
    }else if(index == 6){
        board[1][2] = sign;
        changeCurrentplayer();
    }else if(index == 7){
        board[2][0] = sign;
        changeCurrentplayer();
    }else if(index == 8){
        board[2][1] = sign;
        changeCurrentplayer();
    }else if(index == 9){
        board[2][2] = sign;
        changeCurrentplayer();
    }else{
        printf("\n%s you have made the wrong choice please choose from 1 to 9",name);
    }
}

int boardIsFilled(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' '){
                return 0; // board is not filled
            }
        }
    }
    return 1; // board is filled
}

int getPlayerFromSign(char sign){
    if(player1_choice == sign){
        return 0;
    }else{
        return 1;
    }
}

char* returnPlayerName(int playerIndex){
    if(playerIndex == 0) return player1_name;
    else return player2_name;
}

char* checkWinner(){
    int player;
    if(board[0][0] == board[0][1] and board[0][1] == board[0][2] and board[0][0] != ' '){
        player = getPlayerFromSign(board[0][0]);
        return returnPlayerName(player);
    }else if(board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][0] != ' '){
        player = getPlayerFromSign(board[1][0]);
        return returnPlayerName(player);
    }else if(board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][0] != ' '){
        player = getPlayerFromSign(board[2][0]);
        return returnPlayerName(player);
    }else if(board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[0][0] != ' '){
        player = getPlayerFromSign(board[0][0]);
        return returnPlayerName(player);
    }else if(board[0][1] == board[1][1] and board[1][1] == board[2][1] and board[0][1] != ' '){
        player = getPlayerFromSign(board[0][1]);
        return returnPlayerName(player);
    }else if(board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[0][2] != ' '){
        player = getPlayerFromSign(board[0][2]);
        return returnPlayerName(player);
    }else if(board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] != ' '){
        player = getPlayerFromSign(board[0][0]);
        return returnPlayerName(player);
    }else if(board[2][0] == board[1][1] and board[1][1] == board[0][2] and board[2][0] != ' '){
        player = getPlayerFromSign(board[0][2]);
        return returnPlayerName(player);
    }else{
        return "no winner";
    }
}

int main(){
    int counter = 0;
    int index;
    int boardFilled;
    char *winner="no winner";
    initializeBoard();
    printf("Enter your name player 1: ");
    scanf("%s",player1_name);
    printf("Enter your name player 2: ");
    scanf("%s",player2_name);
    printf("\n%s what do you want o or x?",player1_name);
    scanf(" %c",&player1_choice);
    if(player1_choice == 'o'){
        player2_choice = 'x';
    }else{
        player2_choice = 'o';
    }
    boardFilled = boardIsFilled();
    currentPlayer = 0;

    while(!boardFilled and winner=="no winner"){
        system("cls");
        printBoard();
        if(currentPlayer == 0){ // player 1's turn
            printf("\n%s Enter the index number where you want to put \'%c\'",player1_name,player1_choice);
            scanf("%d",&index);
            fillEntry(index,player1_choice,player1_name);
        }else{ // player 2's turn
            printf("\n%s Enter the index number where you want to put \'%c\'",player2_name,player2_choice);
            scanf("%d",&index);
            fillEntry(index,player2_choice,player2_name);
        }
        boardFilled = boardIsFilled();
        winner = checkWinner();
        if(winner != "no winner"){
            system("cls");
            printBoard();
            printf("Congratulations!!\nWinner of this game is %s.",winner);
        }
    }if(winner == "no winner"){
        char answer;
        system("cls");
        printBoard();
        printf("Oops!!\nMatch is draw.\nNo one won the match!\n Do you want to play again?(y/n)");
        scanf(" %c",&answer);
        if(answer == 'y'){
            system("cls");
            main();
        }
    }
    return 0;
}
