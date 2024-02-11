#include<stdio.h>
#include<conio.h>
int main(){

    printf("\t \t \t \t RULE OF THIS GAME\n\n");

    printf("1. You can move only 1 step at a time by arrow key\n");
    printf("Move Up    : by Up arrow key\n");
    printf("Move Down  : by Down arrow key\n");
    printf("Move Left  : by Left arrow key\n");
    printf("Move Right : by Right arrow key\n");

    printf("2. You can move number at empty position only \n \n");
    printf("3. For each valid move : your total number of move will decreased by 1\n");
    printf("4. Winning situation    : number in a 4*4 matrix should be in order from 1 to 15\n \n");
    printf("Winning Situation: \n");
    printf("---------------------\n");
    printf("| 1  | 2  | 3  | 4  |\n");
    printf("| 5  | 6  | 7  | 8  |\n");
    printf("| 9  | 10 | 11 | 12 |\n");
    printf("| 13 | 14 | 15 |    |\n");
    printf("---------------------\n");

    printf("5.You can exit the game at any time by pressing 'E' or 'e' \n");
    printf("So Try to win in missing no of move\n \n \n");
    printf("\t \t \t Happy Gaming, Good Luck\n \n \n ");
    printf("Enter any key to start. . . . . .   ");
    int x  = getch();
    clrscr();

    if(x){
        // clrscr();
    }

    return 0;
}