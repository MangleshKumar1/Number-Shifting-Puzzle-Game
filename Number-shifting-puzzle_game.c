#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define ANSI_COLOR_RED  "\e[0;31m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_RESET "\e[0m"
#define ANSI_COLOR_YELLOW "\e[0;33m"
#define ANSI_COLOR_CYAN "\e[0;37m"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to shuffle an array
void shuffle(int arnum[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arnum[i], &arnum[j]);
    }
}

void createMatrix(int arr[][4])
{
    // Initialize array with numbers from 1 to 15
    int nums[15];
    for (int i = 0; i < 15; i++)
    {
        nums[i] = i + 1;
    }

    // Shuffle the array
    srand(time(0));
    shuffle(nums, 15);

    // Fill the 4x4 array with shuffled numbers
    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (index < 15)
            {
                arr[i][j] = nums[index++];
            }
            else
            {
                arr[i][j] = 0; // Last element is 0
            }
        }
    }
}

void showMatrix(int arr[][4])
{
    int i, j;

    printf("Generated 4x4 array:\n");
    printf("------------\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("------------\n");
}

int winner( int arr[][4]){
    int i, j, k = 1;
    for (i = 0; i < 4;i++){
        for (j = 0; j < 4; j++){
            if(arr[i][j] != k && k!=16){
                break;
            }
        }
            if (j < 4)
                break;
    }

    if(j<4)
        return 0;
    return 1;
}


int readEnteredKey(){
    char c;
    c = _getch(); 
    // function to read a character from the keyboard without echoing it to the screen.

    if(c== -32)// some systems use -32 as an escape character or a prefix for special keys.
        c = _getch(); //_getch() is called again to read the actual key code.
    //character is - 32, it means that it's a special key
}


int shiftUp(int arr[][4]){
    int i, j;
    for (i = 0; i < 4;i++)
    {
        for (j = 0; j < 4;j++){
            if(arr[i][j]==0){
                break;
            }
        }
        if(j<4)
            break;
    }
    if (i == 3) // shifting not possible
        return 0;

    //successfully swapped two numbers
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1;//success
}

int shiftDown(int arr[][4]){
    int i, j;
    for (i = 0; i < 4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i-1][j]);
    return 1; // shift up success
}


int shiftRight(int arr[][4]){
    int i, j;
    for (i = 0; i < 4;i++)
    {
        for (j = 0; j < 4;j++){
            if(arr[i][j]==0){
                break;
            }
        }
        if(j<4)
            break;
    }
    if(j==0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);
    return 1; // shift up success
}


int shiftLeft(int arr[][4]){
    int i, j;
    for (i = 0; i < 4;i++)
    {
        for (j = 0; j < 4;j++){
            if(arr[i][j]==0){
                break;
            }
        }
        if (j < 4)
            break;
    }
     if(j==3) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
} 


void gameRule( int arr[][4]){

    int i, j, k = 1;
    printf("\t\t\t \t    MATRIX PUZZLE\n ");
    printf(ANSI_COLOR_GREEN "\t \t \t \t RULE OF THIS GAME\n" ANSI_COLOR_RESET);

    printf(ANSI_COLOR_CYAN "\n1. You can move only 1 step at a time by arrow key\n" ANSI_COLOR_RESET);
    printf("\tMove Up    : by Up arrow key\n");
    printf("\tMove Down  : by Down arrow key\n");
    printf("\tMove Left  : by Left arrow key\n");
    printf("\tMove Right : by Right arrow key\n");

    printf(ANSI_COLOR_CYAN "2. You can move number at empty position only \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "3. For each valid move : your total number of move will decreased by 1\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "4. Winning situation    : number in a 4*4 matrix should be in order from 1 to 15\n \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "\t \t \t  Winning Situation: \n" ANSI_COLOR_RESET);
    printf("---------------------\n");
    printf("| 1  | 2  | 3  | 4  |\n");
    printf("| 5  | 6  | 7  | 8  |\n");
    printf("| 9  | 10 | 11 | 12 |\n");
    printf("| 13 | 14 | 15 | 0  |\n");
    printf("---------------------\n");

    printf(ANSI_COLOR_CYAN "5.You can exit the game at any time by pressing 'E' or 'e' \n" ANSI_COLOR_RESET);
    printf("So Try to win in missing no of move\n \n \n");
    printf("\t \t \t Happy Gaming, Good Luck\n \n \n ");
    printf(ANSI_COLOR_YELLOW "Enter any key to start. . . . . .   " ANSI_COLOR_RESET);

    int x = readEnteredKey();
}


//main()
int main()
{
    int arr[4][4]={0}; //matrix initialized
    int maxTry = 16;// maximum move
    char name[20];

    for (int k = 0; k < 3;k++){ // For top 3 lines empty
        printf("\n");
    }

    printf("Player Name: ");
    scanf("%s", name);

    system("cls"); // to clear screen

//next screen 
    while(1){
        createMatrix(arr); // calling function to create matrix
        gameRule(arr);//game rule function calling

        while(!winner(arr))// checking for winning situation
        {
            system("cls");
            if(!maxTry)// for remaining zero move
                break;

            printf("\n\n Player Name: %s , Move remaining : %d\n\n", name, maxTry);

            showMatrix(arr);// show matrix

            int key = readEnteredKey();//this will return scan code of arrow key entered

            switch(key)// maping
            {
                case 101:// scan code of E, if user click for exit next case will automatically run

                case 69: //scan code of e, if user click for exit
                    printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                    //    \a produce alert sound
                    printf("\n Hit 'Enter' to exit the game \n");
                    key = readEnteredKey();
                    return 0;

                case 72:// arrow up is pressed, 72 is scan code for arrow up
                    if(shiftUp(arr)){
                        maxTry--;// reducing no. of attempts/move
                        break;
                    }
                case 80:// arrow down is pressed, 80 is scan code for arrow down
                    if(shiftDown(arr)){
                        maxTry--;// reducing no. of attempts/moves
                        break;
                    }
                case 77:
                    if(shiftRight(arr)){
                        maxTry--;// reducing no. of attempts
                        break;
                    }
                case 75:// arrow left is pressed, 75 is scan code for arrow up
                    if(shiftLeft(arr)){
                        maxTry--;// reducing no. of attempts
                        break;
                    }
                default :  printf("\n\n    \a \a Not Allowed \a");
                    //    \a produce alert sound
            }
        }

        if(!maxTry){
            printf(ANSI_COLOR_RED "\n \a         YOU lOSE ! \a\a\n");
        }else{
            printf(ANSI_COLOR_GREEN "\n \a!!!!!!Congratulations  %s YOU WIN the Game \a\a\n", name);
        }

        fflush(stdin);// will clear the buffer
        char check;
        printf(ANSI_COLOR_GREEN "\n Want to play again ? \n" ANSI_COLOR_RESET);
        printf("Enter 'y' to play again:  ");
        scanf("%c", &check);

        // Leave the game here itself  !
        if ((check != 'y') && (check != 'Y'))
            break;

        maxTry = 16;
        }
    return 0;
}