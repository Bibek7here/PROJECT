#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

void shuffle( int matrix[][4])
{
    int n=15;
    int num[n];
    int i,j,temp;
    for(i=0; i<n; i++)
    {
        num[i]=i+1;
    }
    int lastindex=n-1;
    srand(time(NULL));
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(lastindex>=0)
            {
                temp=rand() % (lastindex+1);
                matrix[i][j]=num[temp];
                num[temp]=num[lastindex--];
            }
        }
    }
    matrix[i-1][j-1]=0;

}
//to display game rules
void game_rules()
{
    int arr[4][4];
    int i,j,count=1;
    printf("RULE OF THIS GAME");
    printf("\n1.You can move only 1 step at a time by arrow key");
    printf("\nMove Up : by up arrow key");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Right : by right arrow key");
    printf("\nMove Left : by left arrow key");
    printf("\n2.You can move number at empty position only");
    printf("\n\n3.For each valid move : your total number of move will decreased by 1");
    printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15");
    printf("\n\nWinning situation: \n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++,count++)
        {
            if(count!=16)
            {
                arr[i][j]=count;
                printf("|%2d|",arr[i][j]);
            }
            else
            {
                printf("|  |");
            }
        }
        printf("\n");
    }
    printf("\nYou can exit the game at any time by pressing 'E' or'e'\nSo try to win in minimum no of move");
    printf("\n\nHappy gaming, good luck");
    printf("\nEnter any key to start. . . . .   ");
    getch();
}
int readElement()
{
    char c;
    c=getch();
    return c;
}

// to change the into desire position
int change_position(int matrix[][4])
{
    int i,j,temp;
    char arrow;
    int cont;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            temp=0;
            if(matrix[i][j]==0)
            {
                fflush(stdin);
                arrow=readElement();
                if(arrow==72)
                {
                    if(i!=3)
                    {
                        cont=matrix[i][j];
                        matrix[i][j]=matrix[i+1][j];
                        matrix[i+1][j]=cont;
                        temp=1;
                        return 1;
                    }   
                }
                else if(arrow==80)
                {
                    if(i!=0)
                    {
                        cont=matrix[i][j];
                        matrix[i][j]=matrix[i-1][j];
                        matrix[i-1][j]=cont;
                        temp=1;
                        return 1;
                    }
                }
                else if(arrow==75)
                {
                    if(j!=3)
                    {
                        cont=matrix[i][j];
                        matrix[i][j]=matrix[i][j+1];
                        matrix[i][j+1]=cont;
                        temp=1;
                        return 1;
                    }
                }
                else if(arrow==77)
                {
                    if(j!=0)
                    {
                        cont=matrix[i][j];
                        matrix[i][j]=matrix[i][j-1];
                        matrix[i][j-1]=cont;
                        temp=1;
                        return 1;
                    }
                }
                else if(arrow==101 || arrow==69)
                {
                    return 2;
                }
            }
        }
    }
}
int won_or_not(int mat[][4])
{
    int i,j,count=1,check;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            check=0;
            if(mat[i][j]!=count)
            {
                check=1;
                break;
            }
            else if(count==15)
            {
                check=2;
                break;
            }
            count++;
        }
        if(check==1)
        {
            return 1;
        }
        else if(check==2)
        {
            return 2;
        }
    }
}

void display_matrix(int matrix[][4])
{
    int i,j;
    printf("\n----------------\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            // printf("|");
            if(matrix[i][j]!=0)
            {
                printf("|%-2d|",matrix[i][j]);
            }
            else
            {
                printf("|  |");
            }
        }
        printf("\n");
    }
    printf("----------------\n");
}

int main()
{
    int matrix[4][4];
    char exit;
    char name[20];
    int move=7,key,temp;
    printf("Enter your name: ");
    scanf("%s",&name);
    do
    {
        shuffle(matrix);
        game_rules();
        while(1)
        {
            system("cls");
            printf("Hello %s, Move remaining: %d",name,move);
            display_matrix(matrix);
            temp=change_position(matrix);
            if(temp==1 && won_or_not(matrix)==1)
            {
                move--;
            }
            else if(won_or_not(matrix)==2)
            {
                system("cls");
                printf("\nyou won!!");
                break;
            }
            else if(temp==2)
            {
                break;
            }
            if(move==0)
            {
                system("cls");
                printf("\nGame over you lose!!");
                break;
            }
        }
        printf("\nDo you want to play again?");
        printf("\nEnter Y or y to play again: ");
        fflush(stdin);
        scanf("%c",&exit);
        if(exit=='y' || exit=='Y')
        {
            move=7;
        }
        else
        {
            break;
        }
    }while(1);
    return 0;
}
