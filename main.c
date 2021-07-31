#include <stdio.h>
#include<time.h>
#include"functions.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversions"
#pragma GCC diagnostic pop




int board[22][22];
int x2,y2;
int turn = 1;
int winnerScore,winnerPlayer;


struct GameState{

    int status;
    int control;
    int totalFish;
    int numberOfPenguin;// To arrange limit of penguins number
    int numberOfPlayers;// To arrange limit of the player number
};



int main()
{

    struct GameState game;
    game.status=0;
    game.control=0;
    game.totalFish = 700;
    game.numberOfPenguin = 14;


/* --------------------------------------------------------------------------  */
    // to have dynamic array
    int numberOfElement = 20*20;
    int *memory;

    memory = malloc(numberOfElement * sizeof(int));

    if( memory == NULL)
    {
        printf("Error");
        return 0;
    }

    free(memory);
/* --------------------------------------------------------------------------  */

    srand(time(NULL));
    int blackPenguenCount = 3;
    int whitePenguenCount = 3;
    int j = 0;
    int i =0;

    int x;
    int y;


    for(i=0;i<22;i++)
        for(j=0;j<22;j++) board[i][j]=10; // I used this code to add the ice floes.




    FishPlacing(game.totalFish);

    PrintBoard();



    int *returnFonc =  PenguinPlacing(game.numberOfPenguin,game.control);

    game.numberOfPenguin = *(returnFonc + 0); // I did necessary assign for returned varriable
    game.numberOfPlayers = *(returnFonc + 1);

    game.status = 0;

    movement(game.status,game.numberOfPlayers,game.numberOfPenguin);

    return;
}

void movement(int status,int numberOfPlayers,int numberOfPenguin)
{
    int scores[numberOfPlayers];

    for(int i = 0;i<numberOfPlayers;i++)
    {
        scores[i] = numberOfPenguin; // At the beginnig, scores of all players are equal to penguins number
    }


    int column,row;
    int chooseColumn, chooseRow;
    while(status == 0)
    {
        printf("\n%d. player turn\n",turn);


        if (turn == 1)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                                // this code checks if the player 1 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 1);
        }
        else if (turn == 2)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                              // this code checks if the player 2 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 2);
        }
        else if (turn == 3)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                             // this code checks if the player 3 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 3);
        }
        else if (turn == 4)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                            // this code checks if the player 4 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 4);
        }
        else if (turn == 5)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                          // this code checks if the player 5 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 5);
        }
        else if (turn == 6)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                          // this code checks if the player 6 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 6);
        }
        else if (turn == 7)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                         // this code checks if the player 7 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 7);
        }
        else if (turn == 8)
        {
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                          // this code checks if the player 8 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 8);
        }
        else{
            do
            {
                printf("Please enter the column of the penguen: ");
                scanf("%d",&chooseColumn);                          // this code checks if the player 9 has penguin in the location.

                printf("Please enter the row of the penguen: ");
                scanf("%d",&chooseRow);
            }while(board[chooseRow][chooseColumn] != 9);
        }

        printf("PLACE TO MOVE: \n");

        x2=21;
        while(x2<0 || x2>20){
                printf("COLUMN(0-20) : "); scanf("%d",&x2);        // This code helps us to make movement in board dimensions
        }

        y2=21;
        while(y2<0 || y2>20){
                printf("LINE(0-20) : "); scanf("%d",&y2);
        }


        if(turn==1) // Player 1 movement phase
        {
             // Movement validation for vertical
            if( (board[y2][x2] == 11 || board[y2][x2] == 12 || board[y2][x2] == 13) && (abs(chooseRow-y2) == 1) && (abs(chooseColumn-x2) == 0))
            {
                if(board[y2][x2] == 11)
                {
                    scores[turn-1]+=1;
                }
                else if(board[y2][x2] == 12)   // Gain scores
                {
                    scores[turn-1]+=2;
                }
                else if(board[y2][x2] == 13)
                {
                    scores[turn-1]+=3;
                }
                board[y2][x2]=board[chooseRow][chooseColumn];
                board[chooseRow][chooseColumn]=14;
                for(int i = 1;i<numberOfPlayers;i++)
                {
                    if(i+1 <= numberOfPlayers)
                    {
                        int kontrol = CheckIfGamesOverByPlayer(numberOfPenguin,i+1);
                        if(kontrol == 1)
                        {
                            turn=i+1;                      // Check turns
                            break;
                        }
                    }
                }
            }
            // Movement validation for horizontal
            else if((board[y2][x2] == 11 || board[y2][x2] == 12 || board[y2][x2] == 13) && (abs(chooseRow-y2) == 0) && (abs(chooseColumn-x2) == 1))
            {
                if(board[y2][x2] == 11)
                {
                    scores[turn-1]+=1;
                }
                else if(board[y2][x2] == 12)     // Gain scores
                {
                    scores[turn-1]+=2;
                }
                else if(board[y2][x2] == 13)
                {
                    scores[turn-1]+=3;
                }
                board[y2][x2]=board[chooseRow][chooseColumn];
                board[chooseRow][chooseColumn]=14;

                for(int i = 1;i<numberOfPlayers;i++)
                {
                    if(i+1 <= numberOfPlayers)
                    {
                        int kontrol = CheckIfGamesOverByPlayer(numberOfPenguin,i+1);
                        if(kontrol == 1)
                        {
                            turn=i+1;                    // Check turns
                            break;
                        }
                    }
                }
            }

        }

        for(int i =2;i<=numberOfPlayers;i++)
        {
            if(turn==i) // Player 2 or others movement phase
            {
                if( (board[y2][x2] == 11 || board[y2][x2] == 12 || board[y2][x2] == 13) && (abs(chooseRow-y2) == 1) && (abs(chooseColumn-x2) == 0)   )
                {
                    if(board[y2][x2] == 11)
                    {
                        scores[turn-1]+=1;
                    }
                    else if(board[y2][x2] == 12)                    // Gain scores
                    {
                        scores[turn-1]+=2;
                    }
                    else if(board[y2][x2] == 13)
                    {
                        scores[turn-1]+=3;
                    }
                    board[y2][x2]=board[chooseRow][chooseColumn];
                    board[chooseRow][chooseColumn]=14;


                    if(turn+1 > numberOfPlayers)
                    {

                        for(int i =1 ;i<=numberOfPlayers;i++)
                        {
                            int a = CheckIfGamesOverByPlayer(numberOfPenguin,i);
                            if(a == 1)
                            {
                                turn=i;                                 // Check turns
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(int i = turn;i<numberOfPlayers;i++)
                        {
                            int d = CheckIfGamesOverByPlayer(numberOfPenguin,i+1);
                            if(i+1 <= numberOfPlayers && d == 1)
                            {
                                turn=i+1;                           // Check turns
                                break;
                            }
                            else if(i == numberOfPlayers-1 && d == 0)
                            {
                                for(int i =1 ;i<=numberOfPlayers;i++)
                                {
                                    int a = CheckIfGamesOverByPlayer(numberOfPenguin,i);
                                    if(a == 1)
                                    {
                                        turn=i;                      // Check turns
                                        break;
                                    }
                                }
                            }
                        }
                    }


                }
                else if((board[y2][x2] == 11 || board[y2][x2] == 12 || board[y2][x2] == 13) && (abs(chooseRow-y2) == 0) && (abs(chooseColumn-x2) == 1))
                {
                    if(board[y2][x2] == 11)
                    {
                        scores[turn-1]+=1;
                    }
                    else if(board[y2][x2] == 12)                    // Gain scores
                    {
                        scores[turn-1]+=2;
                    }
                    else if(board[y2][x2] == 13)
                    {
                        scores[turn-1]+=3;
                    }
                    board[y2][x2]=board[chooseRow][chooseColumn];
                    board[chooseRow][chooseColumn]=14;


                    if(turn+1 > numberOfPlayers)
                    {

                        for(int i =1 ;i<=numberOfPlayers;i++)
                        {
                            int a = CheckIfGamesOverByPlayer(numberOfPenguin,i);
                            if(a == 1)
                            {
                                turn=i;                      // Check turns
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(int i = turn;i<numberOfPlayers;i++)
                        {
                            int c = CheckIfGamesOverByPlayer(numberOfPenguin,i+1);
                            if(i+1 <= numberOfPlayers && c == 1)
                            {
                                turn=i+1;                               // Check turns
                                break;
                            }
                            else if(i == numberOfPlayers-1 && c == 0)
                            {
                                for(int i =1 ;i<=numberOfPlayers;i++)
                                {
                                    int a = CheckIfGamesOverByPlayer(numberOfPenguin,i);
                                    if(a == 1)
                                    {
                                        turn=i;                      // Check turns
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }


            }
        }

        PrintBoard();

        for(int i=0;i<numberOfPlayers;i++)
        {
            printf("%d. Player's score is : %d - ",i+1,scores[i]);     //Print the scores of the players
        }

        int totalPenguin = numberOfPlayers*numberOfPenguin;

        int result = CheckIfGameOver(numberOfPenguin, numberOfPlayers);

        if(result == 1)
        {
            printf("Game is Over !!!");

            winnerScore = scores[0];
            winnerPlayer = 1;

            for(int i = 1;i<numberOfPlayers;i++)
            {

                if(scores[i] > winnerScore)
                {
                    winnerScore = scores[i];
                    winnerPlayer = i+1;
                }
            }
            for(int i = 1;i<numberOfPlayers;i++)
            {

                if(scores[i] == winnerScore)
                {
                    printf("There is one more Winner\nScore is : %d \nPlayer is : %d ", scores[i],i+1);
                }
            }
            printf("\nThe Winner Score is : %d\n ", winnerScore);
            printf("\nThe Winner Player is : %d\n ", winnerPlayer);

            FILE *fp;

            if ((fp = fopen ("file.txt", "w")) == NULL)
            {
                printf("Error !!!");
            }

            fprintf(fp,"The Winner Score is : %d, The Winner Player is : %d", winnerScore, winnerPlayer);

            fclose(fp);

            int exit; //this code closes at the end, after pressing any button

            printf("\nPress any button to exit the game: ");

            scanf("%d", &exit);
            if(exit==0){return 0;}
            else{return 0;}

        }


    }
}

int CheckIfGameOver(int numberOfPenguin, int numberOfPlayers)
{

    int isGameOver=0;

    int totalPenguin = numberOfPenguin*numberOfPlayers;

    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            for(int k=0;k<numberOfPlayers+1;k++)
            {
                if(board[i][j] == k && (board[i+1][j] != 11 && board[i+1][j] != 12 &&  board[i+1][j] != 13) &&
                (board[i-1][j] != 11 && board[i-1][j] != 12 &&  board[i-1][j] != 13) &&
                (board[i][j+1] != 11 && board[i][j+1] != 12 &&  board[i][j+1] != 13) &&                 //Checks each penguins in the board if they can move or not
                (board[i][j-1] != 11 && board[i][j-1] != 12 &&  board[i][j-1] != 13))
                {
                    isGameOver++;
                }
                if(isGameOver ==  totalPenguin )
                {
                    int resultOver = 1;
                                            //This code finishes the game if blocked penguin number is equal to total penguin number


                    return resultOver;
                }
                else if(i == 20 && j == 20 && k == numberOfPlayers-1 && isGameOver != totalPenguin )
                {

                    int resultContinue = 2;             //When all board is checked This code continues the game if blocked penguin number is not equal to total penguin number
                    return resultContinue;
                }
            }
        }
    }
}

int CheckIfGamesOverByPlayer(int numberOfPenguin,int player)
{

    int isGameOver=0;

    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            if(board[i][j] == player && (board[i+1][j] != 11 && board[i+1][j] != 12 &&  board[i+1][j] != 13) &&
            (board[i-1][j] != 11 && board[i-1][j] != 12 &&  board[i-1][j] != 13) &&
            (board[i][j+1] != 11 && board[i][j+1] != 12 &&  board[i][j+1] != 13) &&         //This code finishes the movement phase for one player when blocked penguin number is equal to  penguin number per player
            (board[i][j-1] != 11 && board[i][j-1] != 12 &&  board[i][j-1] != 13))
            {
                isGameOver++;
            }
            if(isGameOver == numberOfPenguin )
            {
                int falseValue = 0;
                return falseValue;
            }
            else if(i == 20 && j == 20 && isGameOver != numberOfPenguin)
            {

                int trueValue = 1;

                return trueValue;
            }

        }
    }
}

void FishPlacing(int TotalFish)
{
    while(TotalFish > 0)
    {
        int randomX = rand() % 21;
        int randomY = rand() % 21;

        int k,l;

        for(k=1;k<=20;k++)
        {
            for(l=1;l<=20;l++)
            {
                if(k == randomX && l == randomY)
                {
                    int numberOfFish = rand() % 4;
                    if(numberOfFish == 1 && board[randomX][randomY]==10)
                        board[randomX][randomY] = 11;
                    else if(numberOfFish == 2 && board[randomX][randomY]==10)
                        board[randomX][randomY] = 12;
                    else if(numberOfFish == 3 && board[randomX][randomY]==10)
                        board[randomX][randomY] = 13;

                    TotalFish -= numberOfFish;
                }
            }
        }
    }
}

int PenguinPlacing(int numberOfPenguin, int control)
{
    while(numberOfPenguin > 5)
    {
        printf("Please enter the number of penguins for per player (Between 0 - 5): ");
        scanf("%d",&numberOfPenguin);
    }

    int numberOfPlayers;

    printf("Between 0 - 9 \n");
    printf("Please enter the number of players: ");
    scanf("%d",&numberOfPlayers);

    if(numberOfPlayers > 0 && numberOfPlayers <= 9)
    {
        int totalPenguin = numberOfPenguin * numberOfPlayers;
        int loopPenguin;
        int turn = 1;
        int column,row;


//        FishPlacing();
//        PrintBoard();
        while(control != totalPenguin)
        {


            printf("%d. player turn\n",turn);

            printf("Please enter the column of the location: ");
            scanf("%d",&column);

            printf("Please enter the row of the location: ");
            scanf("%d",&row);

            if(board[row][column] == 11)
            {
                board[row][column] = turn;
                turn++;
                control++;
            }
            else
            {
                printf("You should select the ice floe unoccupied and only one fish\n");
            }
            if(turn == numberOfPlayers+1)
                turn = 1;
            PrintBoard();

        }
    }
    else
    {
        printf("Something is wrong");
        return;
    }

    static int returnFonc[2];

    returnFonc[0] = numberOfPenguin;
    returnFonc[1] = numberOfPlayers;

    return returnFonc;
}


void PrintBoard()
{
    int i, j;
    printf("    ");
    for(i=1;i<=20;i++)
    {
        if(i==0){

            printf("   %d   ",i);   // this part prints columns on screen (numbers above). If else helps us to arrange the blanks in the board.
        }
        else{
            printf("  %d   ",i);
        }
    }

    printf("\n");

    for(i=1;i<=20;i++){

        printf(" %d ",i); // This part prints the row.

        for(j=1;j<=20;j++)
        {
            switch(board[i][j])
            {

                case 1:
                    {
                        if(j>=10)
                        {
                            printf("   P1  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P1  ");
                        }
                        else
                        {
                            printf("  P1  ");
                        }  break;// 1. player's penguen
                    }
                case 2:
                    {
                        if(j>=10)
                        {
                            printf("   P2  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P2  ");
                        }
                        else
                        {
                            printf("  P2  ");//2. player's penguen
                        }

                        break;
                    }
                case 3:
                    {
                        if(j>=10)
                        {
                            printf("   P3  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P3  ");
                        }
                        else
                        {
                            printf("  P3  ");//3. player's penguen
                        }

                        break;
                    }
                case 4:
                    {
                        if(j>=10)
                        {
                            printf("   P4  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P4  ");
                        }
                        else
                        {
                            printf("  P4  ");//4. player's penguen
                        }

                        break;
                    }
                case 5:
                    {
                        if(j>=10)
                        {
                            printf("   P5  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P5  ");
                        }
                        else
                        {
                            printf("  P5  ");//5. player's penguen
                        }

                        break;
                    }
                case 6:
                    {
                        if(j>=10)
                        {
                            printf("   P6  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P6  ");
                        }
                        else
                        {
                            printf("  P6  ");//6. player's penguen
                        }
                        break;
                    }
                case 7:
                    {
                        if(j>=10)
                        {
                            printf("   P7  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P7  ");
                        }
                        else
                        {
                            printf("  P7  ");//7. player's penguen
                        }

                        break;
                    }
                case 8:
                    {
                        if(j>=10)
                        {
                            printf("   P8  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P8  ");
                        }
                        else
                        {
                            printf("  P8  ");//8. player's penguen
                        }

                        break;
                    }
                case 9:
                    {
                        if(j>=10)
                        {
                            printf("   P9  ");
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   P9  ");//9. player's penguen
                        }
                        else
                        {
                            printf("  P9  ");
                        }

                        break;
                    }


                case 10:
                    {
                        if(j>=10)
                        {
                            printf("   -   ");
                        }
                        else if(j==1 && i<=9)//Empty
                        {
                            printf("   -   ");
                        }
                        else
                        {
                            printf("  -   ");
                        }


                         break;
                    }



                case 11:
                    {
                        if(j>=10)
                        {
                            printf(     "   1   " );// Number of fish = 1
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   1   ");
                        }
                        else
                        {
                            printf("  1   ");
                        }
                         break;

                    }

                case 12:
                    {
                        if(j>=10)
                        {
                            printf("   2   ");//Number of fish = 2
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   2   ");
                        }
                        else
                        {
                            printf("  2   ");
                        }
                        break;

                    }

                case 13:
                    {
                        if(j>=10)
                        {
                            printf("   3   ");//Number of fish =3
                        }
                        else if(j==1 && i<=9)
                        {
                            printf("   3   ");
                        }
                        else
                        {
                            printf("  3   ");
                        }
                        break;

                    }

                case 14:
                    {
                        if(j>=10)
                        {

                            printf("   X   ");

                        }
                        else if(j==1 && i<=9)//Empty
                        {

                            printf("   X   ");

                        }
                        else
                        {

                            printf("   X   ");

                        }

                        break;//This is removed flow

                    }
            }
        }
    printf("\n\n");
    }
}
