#include <stdio.h>
int board[3][3];
void printBoard()
{
    char tmp;
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("|");
        for(j=0;j<3;j++)
        {
            switch(board[i][j])
            {
                case 1:tmp='X';break;
                case 0: tmp=' ';
                    break;
                case -1:tmp='O';
                    break;

            }
            printf(" %c|",tmp);
        }
        printf("\n");
    }
}
int winner()
{
    int i;
    if(board[0][0]+board[1][1]+board[2][2]==3)
        return 1;
    if(board[0][0]+board[1][1]+board[2][2]==-3)
        return -1;
    for(i=0;i<3;i++) {
        if (board[i][0] + board[i][1] + board[i][2] == 3)
            return 1;
        if (board[i][0] + board[i][1] + board[i][2] == -3)
            return -1;
    }
    for(i=0;i<3;i++) {
        if (board[0][i] + board[1][i] + board[2][i] == 3)
            return 1;
        if (board[0][i] + board[1][i] + board[2][i] == -3)
            return -1;
    }
    return 0;
}
int main() {
    int t,tmp;
    int k=1;
    do
    {
        printBoard();
        while(1) {
            if (k == 1)
                printf("turn of X, Input number (0-9):\n");
            else
                printf("Turn of O, Input number(0-9)");

            scanf("%d", &tmp);
            if(board[tmp / 3][tmp % 3] ==0) {
                board[tmp / 3][tmp % 3] = k;
                break;
            }
            else
                printf("Cell already has a piece!\n");
        }
        k*=-1;

    }while((t=winner())==0);
    if(t==1)
        printf("X wins!");
    if(t==-1)
        printf("O wins!");

    return 0;
}