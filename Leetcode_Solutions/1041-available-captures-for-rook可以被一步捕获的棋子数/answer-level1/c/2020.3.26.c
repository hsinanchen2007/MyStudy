### 解题思路
R和B都是大写，p是小写，我佛辣

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
           // printf("%c ",board[i][j]);
            if(board[i][j]=='R')
            {
                int x,y;
                int ans=0;
                x=i;
                y=j;
                while(x>=0)
                {
                    if(board[x][y]=='p')
                    {
                        ans++;
                        break;
                    }
                    if(board[x][y]=='B')
                    {
                        break;
                    }
                    x--;
                }
               // printf("b=%c",board[1][3]);
               // printf("x=%d y=%d \n",x,y);
                x=i;
                y=j;
                while(x<boardSize)
                {
                    if(board[x][y]=='p')
                    {
                        ans++;
                        break;
                    }
                    if(board[x][y]=='B')
                    {
                        break;
                    }
                    x++;
                }
                x=i;
                y=j;
                while(y>=0)
                {
                    if(board[x][y]=='p')
                    {
                        ans++;
                        break;
                    }
                    if(board[x][y]=='B')
                    {
                        break;
                    }
                    y--;
                }
                x=i;
                y=j;
                while(y<*boardColSize)
                {
                    if(board[x][y]=='p')
                    {
                        ans++;
                        break;
                    }
                    if(board[x][y]=='B')
                    {
                        break;
                    }
                    y++;
                }  
                return ans;                              
            }
        }
        //printf("\n");
    }
    return 0;
}
```