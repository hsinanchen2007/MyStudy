### 解题思路
此处撰写解题思路

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i,j,k,a,b,count=0;
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[i];j++)
        {
            if(board[i][j]=='p' && i<(boardSize-1) && j<(boardSize-1) )
            {
                a=i;
                b=j;
                while(board[a][b+1]=='.' && b<(boardSize-2))
                    b++;
                if(board[a][b+1]=='R')
                    count++;
                a=i;
                b=j;
                while(board[a+1][b]=='.' && a<(boardSize-2))
                    a++;
                if(board[a+1][b]=='R')
                    count++;
            }
            else if(board[i][j]=='R' && i<(boardSize-1) && j<(boardSize-1) )
            {
                a=i;
                b=j;
                while(board[a][b+1]=='.' && b<(boardSize-2))
                    b++;
                if(board[a][b+1]=='p')
                    count++;
                a=i;
                b=j;
                while(board[a+1][b]=='.' && a<(boardSize-2))
                    a++;
                if(board[a+1][b]=='p')
                    count++;
            }
        }
    }
    return count;
}
```