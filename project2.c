#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void display(int (*)[3]);//to display the values
int player(int (*)[3]);// for two player gameplay
int Firstchange_position(int (*)[3],int);// to change X into entered number 
int Secondchange_position(int (*)[3],int);//to change O into entered number
int first_player();// to take input of first player
int second_player();//to take input of second player
void smart(int (*)[3]);// to play with smart computer
int smart_placeoccupy(int (*)[3],int);// to place O accordingly
int smart_winmove(int (*)[3]);// to check if win move of computer is possible
void Evil(int (*)[3]);// to play wiht evil computer
int evil_move(int (*)[3],int);// to make evil move 
int evil_winmove(int (*)[3]);// to check if win move of evil computer is possible
int wonornot(int (*)[3],int);//to check whether the game is draw or win
int main()
{
    int i,j,value=1;
    char choice;
    char exit;
    while(1)
    {
        system("cls");
        int matrix[3][3]={1,2,3,4,5,6,7,8,9};
        fflush(stdin);
        printf("Enter your choice: ");
        printf("\n1.Want to play with smart computer");
        printf("\n2.want to play with evil computer");
        printf("\n3.want to play with player");
        printf("\n4.Exit\n\n");
        printf("\nYour choice is: ");
        scanf("%c",&choice);
        switch(choice)
        {
            case '1':
                smart(matrix);
                break;
            case '2':
                Evil(matrix);
                break;
            case '3':
                player(matrix);
                break;
            case '4':
                return 0;
            default:
                break;
        }
        fflush(stdin);
        printf("\nDo you want to play again?");
        printf("\nEnter y to play again: ");
        scanf("%c",&exit);
        if(exit!='y')
        {
            break;
        }
    }
    return 0;
}
void display(int matrix[][3])
{
    int i,j;
    system("cls");
    printf("\nTic Tac Toe");
    printf("\n\nFirst player  X\nSecond player  O\n\n\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]==100)
            {
                printf("    X");
            }
            else if(matrix[i][j]==200)
            {
                printf("    O");
            }
            else
            {
                printf("%5d",matrix[i][j]);
            }
        }
        printf("\n\n\n");
    }
}
int player(int matrix[][3])
{
    int player_map,count=1;
    int temp,check;
    char player1[25],player2[25];
    fflush(stdin);
    printf("\nEnter name of first player: ");
    scanf("%s",&player1);
    fflush(stdin);
    printf("\nEnter name of first player: ");
    scanf("%s",&player2);
    while(1)
    {
        display(matrix);
        fflush(stdin);
        if(count%2)
        {
            player_map=first_player();
            check=Firstchange_position(matrix,player_map);
            if(count>=3)
            {
                temp=wonornot(matrix,100);
                if(temp==1)
                {
                    display(matrix);
                    printf("\nPlayer First WON");
                    break;
                }
                else if(temp==0)
                {
                    display(matrix);
                    printf("\nDraw");
                    break;
                }
            }
            if(check!=1)
            {
                count++;
            }
        }
        else
        {
            player_map=second_player();
            check=Secondchange_position(matrix,player_map);
            if(count>=4)
            {
                temp=wonornot(matrix,200);
                if(temp==1)
                {
                    display(matrix);
                    printf("\nPlayer Second WON");
                    break;
                }
            }
            if(check!=1)
            {
                count++;
            }
        }
    }
    return 0;
}
int Firstchange_position(int matrix[][3], int position_number)
{
    int i,j;
    int temp=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]==position_number)
            {
                matrix[i][j]=100;
                return 0;
            }
            else
            {
                temp=1;
            }
        }
    }
    if(temp==1)
    {
        return 1;
    }
}
int Secondchange_position(int matrix[][3], int position_number)
{
    int i,j;
    int temp=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]==position_number)
            {
                matrix[i][j]=200;
                return 0;
            }
            else
            {
                temp=1;
            }
        }
    }
    if(temp==1)
    {
        return 1;
    }
}
int first_player()
{
    int mapvalue;
    printf("\nFirst player Enter your number: ");
    scanf("%d",&mapvalue);
    return mapvalue;
}
int second_player()
{
    int mapvalue;
    printf("\nSecond player Enter your number: ");
    scanf("%d",&mapvalue);
    return mapvalue;
}
int wonornot(int matrix[][3],int player_symbol)
{
    int i,j,check=0;
    int row,column;
    int diagonal1=1,diagonal2=1;
    for(i=0; i<3; i++)
    {
        row=1;
        column=1;
        for(j=0; j<3; j++)
        {
            if(row==1)
            {
                row=(matrix[i][j]==player_symbol)?1:0;
            }
            if(column==1)
            {
                column=(matrix[j][i]==player_symbol)?1:0;
            }
        }
        if(diagonal1==1)
        {
            diagonal1=(matrix[i][i]==player_symbol)?1:0;
        }
        if(diagonal2==1)
        {
            diagonal2=(matrix[i][2-i]==player_symbol)?1:0;
        }
        if(row==1 || column==1)
        {
            return 1;
        }
    }
    if(diagonal1==1 || diagonal2==1)
    {
        return 1;
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]!=100 && matrix[i][j]!=200)
            {
                check=1;
                break;
            }
        }
        if(check==1)
        {
            break;
        }
    }
    if(check==0)
    {
        return 0;
    }
}
void smart(int matrix[][3])
{
    int count=1,firstplayer,check,temp;
    while(1)
    {
        display(matrix);
        if(count%2)
        {
            firstplayer=first_player();
            check=Firstchange_position(matrix,firstplayer);
            if(count>=3)
            {
                temp=wonornot(matrix,100);
                if(temp==1)
                {
                    display(matrix);
                    printf("\nYOU WON");
                    break;
                }
                else if(temp==0)
                {
                    display(matrix);
                    printf("\nDraw");
                    break;
                }
            }
            if(check!=1)
            {
                count++;
            }
        }
        else
        {
            temp=smart_winmove(matrix);
            if(temp==0)
            {
                smart_placeoccupy(matrix,count);
            }
            temp=wonornot(matrix,200);
            if(temp==1)
            {
                display(matrix);
                printf("\nYOU LOSE!!!");
                break;
            }
            count++;
        }
    }
}
int smart_placeoccupy(int matrix[][3],int look)
{
    int i,j;
    int row,column,diagonal1=0,diagonal2=0;
    for(i=0; i<3; i++)
    {
        row=0;
        column=0;
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]!= 100 && look<3)
            {
                matrix[i][j]=200;
                return 0;
            }
            else if(1)
            {
                if(matrix[i][j]==100)
                {
                    row++;
                }
                if(matrix[j][i]==100)
                {
                    column++;
                }
                if(row==2 && j<2 && matrix[i][j+1]!=200)
                {
                    matrix[i][j+1]=200;
                    return 0;
                }
                else if(row==2 && j==2)
                {
                    if(matrix[i][j-1]!=200 && matrix[i][j-1]!=100)
                    {
                        matrix[i][j-1]=200;
                        return 0;
                    }
                    else if(matrix[i][j-2]!=100 && matrix[i][j-2]!=200)
                    {
                        matrix[i][j-2]=200;
                        return 0;
                    }
                }
                if(column==2 && j<2 && matrix[j+1][i]!=200 )
                {
                    matrix[j+1][i]=200;
                    return 0;
                 
                }
                else if(column==2 && j==2)
                {
                    if(matrix[j-1][i]!=100 && matrix[j-1][i]!=200)
                    {
                        matrix[j-1][i]=200;
                        return 0;
                    }
                    else if(matrix[j-2][i]!=200 && matrix[j-2][i]!=100)
                    {
                        matrix[j-2][i]=200;
                        return 0;
                    }
                }
            }
        }
        if(matrix[i][i]==100)
        {
            diagonal1++;
        }
        if(matrix[i][2-i]==100)
        {
            diagonal2++;
        }
        if(diagonal1==2 && i<2 && matrix[i+1][i+1]!=100 && matrix[i+1][i+1]!=200)
        {
            matrix[i+1][i+1]=200;
            return 0;
        }
        else if(diagonal1==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]==200;
                return 0;
            }
            else if(matrix[i-2][i-2]!=100 && matrix[i-2][i-2]!=200)
            {
                matrix[i-2][i-2]=200;
                return 0;
            }
        }
        if(diagonal2==2 && i<2 && matrix[i+1][2-i-1]!=100 && matrix[i+1][2-i-1]!=200)
        {
            matrix[i+1][2-i-1]=200;
            return 0;
        }
        else if(diagonal2==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]=200;
                return 0;
            }
            else if(matrix[i-2][i]!=100 && matrix[i-2][i]!=200)
            {
                matrix[i-2][i]=200;
                return 0;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]!=100 && matrix[i][j]!=200)
            {
                matrix[i][j]=200;
                return 0;
            }
        }
    }
    return 1;
}
int smart_winmove(int matrix[][3])
{
    int i,j;
    int row,column,diagonal1=0,diagonal2=0;
    for(i=0; i<3; i++)
    {
        row=0;
        column=0;
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]==200)
            {
                row++;
            }
            if(matrix[j][i]==200)
            {
                column++;
            }
            if(row==2 && j<2 && matrix[i][j+1]!=100)
            {
                matrix[i][j+1]=200;
                return 1;
            }
            else if(row==2 && j==2)
            {
                if(matrix[i][j-1]!=100 && matrix[i][j-1]!=200)
                {
                    matrix[i][j-1]=200;
                    return 1;
                }
                else if(matrix[i][j-2]!=100)
                {
                    matrix[i][j-2]=200;
                    return 1;
                }
            }
            if(column==2 && j<2 && matrix[j+1][i]!=100)
            {
                matrix[j+1][i]=200;
                return 1;
            }
            else if(column==2 && j==2)
            {
                if(matrix[j-1][i]!=100 && matrix[j-1][i]!=200)
                {
                    matrix[j-1][i]=200;
                    return 1;
                }
                else if(matrix[j-2][i]!=100)
                {
                    matrix[j-2][i]=200;
                    return 1;
                }
            }
        }
        if(matrix[i][i]==200)
        {
            diagonal1++;
        }
        if(matrix[i][2-i]==200)
        {
            diagonal2++;
        }
        if(diagonal1==2 && i<2 && matrix[i+1][i+1]!=100)
        {
            matrix[i+1][i+1]=200;
            return 1;
        }
        else if(diagonal1==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100)
            {
                matrix[i-1][i-1]=200;
                return 1;
            }
        }
        if(diagonal2==2 && i<2 && matrix[i][2-i-1]!=100)
        {
            matrix[i][2-i-1]=200;
            return 1;
        }
        else if(diagonal2==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100)
            {
                matrix[i-1][i-1]=200;
                return 1;
            }
            else if(matrix[i-2][i]!=100)
            {
                matrix[i-2][i]=200;
                return 1;
            }
        }
    }
    return 0;
}
void Evil(int matrix[][3])
{
    int player_map,count=1;
    int temp,check;
    while(1)
    {
        display(matrix);
        fflush(stdin);
        if(count%2)
        {
            player_map=first_player();
            check=Firstchange_position(matrix,player_map);
            if(count>=3)
            {
                temp=wonornot(matrix,100);
                if(temp==1)
                {
                    display(matrix);
                    printf("\nYOU WON");
                    break;
                }
                else if(temp==0)
                {
                    display(matrix);
                    printf("\nDraw");
                    break;
                }
            }
            if(check!=1)
            {
                count++;
            }
        }
        else
        {
            temp=evil_winmove(matrix);
            if(temp==0)
            {
                evil_move(matrix,count);
            }
            temp=wonornot(matrix,200);
            if(temp==1)
            {
                display(matrix);
                printf("\nYOU LOSE!!!");
                break;
            }
            if(temp==0)
            {
                display(matrix);
                printf("\nDraw");
                break;
            }
            count++;
        }
    }
}
int evil_move(int matrix[][3],int look)
{
    int i,j,check=0;
    int row,column,diagonal1=0,diagonal2=0;
    for(i=0; i<3; i++)
    {
        row=0;
        column=0;
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]!= 100 && look<3)
            {
                matrix[i][j]=200;
                return 0;
            }
            else if(1)
            {
              if(matrix[i][j]==100)
                {
                    row++;
                }
                if(matrix[j][i]==100)
                {
                    column++;
                }
                if(row==2 && j<2 && matrix[i][j+1]!=200)
                {
                    matrix[i][j+1]=200;
                    check=1;
                }
                else if(row==2 && j==2)
                {
                    if(matrix[i][j-1]!=200 && matrix[i][j-1]!=100)
                    {
                        matrix[i][j-1]=200;
                        check=1;
                    }
                    else if(matrix[i][j-2]!=100 && matrix[i][j-2]!=200)
                    {
                        matrix[i][j-2]=200;
                        check=1;
                    }
                }
                if(column==2 && j<2 && matrix[j+1][i]!=200)
                {
                    matrix[j+1][i]=200;
                    check=1;
                 
                }
                else if(column==2 && j==2)
                {
                    if(matrix[j-1][i]!=100 && matrix[j-1][i]!=200)
                    {
                        matrix[j-1][i]=200;
                        check=1;
                    }
                    else if(matrix[j-2][i]!=200 && matrix[j-2][i]!=100)
                    {
                        matrix[j-2][i]=200;
                        check=1;
                    }
                }
            }
        }
        if(matrix[i][i]==100)
        {
            diagonal1++;
        }
        if(matrix[i][2-i]==100)
        {
            diagonal2++;
        }
        if(diagonal1==2 && i<2 && matrix[i+1][i+1]!=200)
        {
            matrix[i+1][i+1]=200;
            check=1;
        }
        else if(diagonal1==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]=200;
                check=1;
            }
            else if(matrix[i-2][i-2]!=100 && matrix[i-2][i-2]!=200)
            {
                matrix[i-2][i-2]=200;
                check=1;
            }
        }
        if(diagonal2==2 && i<2 && matrix[i+1][2-i-1]!=200)
        {
            matrix[i+1][2-i-1]=200;
            check=1;
        }
        else if(diagonal2==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]=200;
                check=1;
            }
            else if(matrix[i-2][i]!=100 && matrix[i-2][i]!=200)
            {
                matrix[i-2][i]=200;
                check=1;
            }
        }
    }
    if(check==1)
    {
        return 1;
    }
    else
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(matrix[i][j]!=100 && matrix[i][j]!=200)
                {
                    matrix[i][j]=200;
                    return 0;
                }
            }
        }
    }
}
int evil_winmove(int matrix[][3])
{
    int i,j;
    int row,column,diagonal1=0,diagonal2=0;
    for(i=0; i<3; i++)
    {
        row=0;
        column=0;
        for(j=0; j<3; j++)
        {
            if(matrix[i][j]==200)
            {
                row++;
            }
            if(matrix[j][i]==200)
            {
                column++;
            }
            if(row==2 && j<2 && matrix[i][j+1]!=100)
            {
                matrix[i][j+1]=200;
                return 1;
            }
            else if(row==2 && j==2)
            {
                if(matrix[i][j-1]!=100 && matrix[i][j-1]!=200)
                {
                    matrix[i][j-1]=200;
                    return 1;
                }
                else if(matrix[i][j-2]!=100 && matrix[i][j-1]!=200)
                {
                    matrix[i][j-2]=200;
                    return 1;
                }
            }
            if(column==2 && j<2 && matrix[j+1][i]!=100)
            {
                matrix[j+1][i]=200;
                return 1;
            }
            else if(column==2 && j==2)
            {
                if(matrix[j-1][i]!=100 && matrix[j-1][i]!=200)
                {
                    matrix[j-1][i]=200;
                    return 1;
                }
                else if(matrix[j-2][i]!=100 && matrix[j-2][i]!=200)
                {
                    matrix[j-2][i]=200;
                    return 1;
                }
            }
        }
        if(matrix[i][i]==200)
        {
            diagonal1++;
        }
        if(matrix[i][2-i]==200)
        {
            diagonal2++;
        }
        if(diagonal1==2 && i<2 && matrix[i+1][i+1]!=100)
        {
            matrix[i+1][i+1]=200;
            return 1;
        }
        else if(diagonal1==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]=200;
                return 1;
            }
        }
        if(diagonal2==2 && i<2 && matrix[i][2-i-1]!=100)
        {
            matrix[i][2-i-1]=200;
            return 1;
        }
        else if(diagonal2==2 && i==2)
        {
            if(matrix[i-1][i-1]!=100 && matrix[i-1][i-1]!=200)
            {
                matrix[i-1][i-1]=200;
                return 1;
            }
            else if(matrix[i-2][i]!=100)
            {
                matrix[i-2][i]=200;
                return 1;
            }
        }
    }
    return 0;
}