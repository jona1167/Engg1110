
/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  :Ng Ka Wah
 * Student ID    :1155162668
 * Class/Section :1110e
 * Date          :14/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            gameBoard[i][j]=EMPTY;

        }


    }


}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
        printf("|");
        if(gameBoard[i][j]==EMPTY)
            printf(" ");
        else if(gameBoard[i][j]==CIRCLE)
            printf("O");
        else if(gameBoard[i][j]==CROSS)
            printf("X");
        }
    printf("|\n");

    }
    printf(" 1 2 3 4 5 6 7\n");
}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    // TODO : Complete this part
    int input,check=0,count=0,temp=0,colcheck=0;//check for input check,count for count empty space,temp for store the row,colcheck is check column
    while(colcheck==0){
    check=0,count=0,temp=0,colcheck=0;
    while(check==0){
        scanf("%d", &input);
        if(input>0&&input<8)
            check=1;
        else
            printf("Input out of range. Please input again:\n");
    }
    input-=1;
    for(int i =0;i<6;i++){
        if(gameBoard[i][input]==EMPTY){
            count++;
            temp=i;

        }
    }
    if(count>0){
        gameBoard[temp][input]=mark;
        colcheck=1;
    }
    else
         printf("Column is full. Please input again:\n");
    }
}



/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){

    // TODO : Complete this part
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(j<4){//horizontal
                if(gameBoard[i][j]!=EMPTY&&gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3])
                    return 1;
            }
            if(i<3){//vertical
                if(gameBoard[i][j]!=EMPTY&&gameBoard[i][j]==gameBoard[i+1][j]&&gameBoard[i+1][j]==gameBoard[i+2][j]&&gameBoard[i+2][j]==gameBoard[i+3][j])
                    return 1;
            }
            if(i>2&&i<6&&j<4){// for /
                if(gameBoard[i][j]!=EMPTY&&gameBoard[i][j]==gameBoard[i-1][j+1]&&gameBoard[i-1][j+1]==gameBoard[i-2][j+2]&&gameBoard[i-2][j+2]==gameBoard[i-3][j+3])
                    return 1;
            }
            if(i>-1&&i<3&&j<4){// for (\)
                if(gameBoard[i][j]!=EMPTY&&gameBoard[i][j]==gameBoard[i+1][j+1]&&gameBoard[i+1][j+1]==gameBoard[i+2][j+2]&&gameBoard[i+2][j+2]==gameBoard[i+3][j+3])
                    return 1;
            }


    }

}
return 0;
}

/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {
    int count =0;
    // TODO : Complete this part
    for(int i =0;i<6;i++){
        for(int j =0;j<7;j++){
            if(gameBoard[i][j]==EMPTY){
                count++;
            }
        }
    }
    if(count>0)
        return 0;
    else
        return 1;

}



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[6][7]){
  int temprow=-1,tempcol=-1;
  int min=-1,tempmin,tempi;
  int count[7]={0};
  
    //cross

    for(int i =0;i<6;i++){//case1
        for(int j=6;j>-1;j--){
            if(gameBoard[i][j]==EMPTY&&(gameBoard[i+1][j]!=EMPTY||i==5)){

                gameBoard[i][j]=CROSS;
                if(hasWinner(gameBoard)==0){
                    gameBoard[i][j]=EMPTY;
                }
                else{
                    temprow=i;
                    tempcol=j;
                    gameBoard[i][j]=EMPTY;
                }
            }


        }

    }
    if(temprow!=-1&&tempcol!=-1){
        gameBoard[temprow][tempcol]=CROSS;
    }
else{
    temprow=-1,tempcol=-1;
   for(int i =0;i<6;i++){//case2
        for(int j=6;j>-1;j--){
            if(gameBoard[i][j]==EMPTY&&(gameBoard[i+1][j]!=EMPTY||i==5)){

                gameBoard[i][j]=CIRCLE;
                if(hasWinner(gameBoard)==0){
                    gameBoard[i][j]=EMPTY;
                }
                else{
                    temprow=i;
                    tempcol=j;
                    gameBoard[i][j]=EMPTY;
                }
            }


        }

    }
    if(temprow!=-1&&tempcol!=-1){
        gameBoard[temprow][tempcol]=CROSS;
    }
else{
    for(int i =0;i<6;i++){//case 3
        for(int j=0;j<7;j++){
            if(gameBoard[i][j]!=EMPTY){
                count[j]++;
            }
        }
    }

    min=count[6];
    tempmin=6;
    for(int i=6;i>-1;i--){
        if(count[i]<min){
            min=count[i];
            tempmin=i;
        }

    }
    for(int i=0;i<6;i++){
    if(gameBoard[i][tempmin]==EMPTY){
        tempi=i;
    }
    }
     gameBoard[tempi][tempmin]=CROSS;
}

}

}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2
    int fin=0,temprow=-1,tempcol=-1;
    int count[7]={0};
    int min=-1,tempmin,tempi;
    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid





    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
if(numOfHumanPlayers==2){//human
    printGameBoard(gameBoard);
while(fin==0){

    printf("Player 1's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    if(isFull(gameBoard)==1){
        fin=1;
        break;
    }
    if(hasWinner(gameBoard)==1){
    printf("Congratulations! Player 1 wins!");
    fin=1;
    break;
    }
    printf("Player 2's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CROSS);
    printGameBoard(gameBoard);
    if(isFull(gameBoard)==1){
        fin=1;
        break;
    }
    if(hasWinner(gameBoard)==1){
    printf("Congratulations! Player 2 wins!");
    fin=1;
    break;
    }
}
if(isFull(gameBoard)==1)
    printf("Draw game.");
}
    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part
if(numOfHumanPlayers==1){//pc
        printGameBoard(gameBoard);
   while(fin==0){
    int count[7]={0};
    printf("Player 1's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    if(isFull(gameBoard)==1){
        fin=1;
        break;
    }
    if(hasWinner(gameBoard)==1){
    printf("Congratulations! Player 1 wins!");
    fin=1;
    break;
    }
    printf("Computer's turn:\n");
    placeMarkByComputerPlayer( gameBoard);
    printGameBoard(gameBoard);
    if(isFull(gameBoard)==1){
        fin=1;
        break;
    }
    if(hasWinner(gameBoard)==1){
    printf("Computer wins!");
    fin=1;
    break;
    }
}
if(isFull(gameBoard)==1)
    printf("Draw game.");











}
    return 0;
}