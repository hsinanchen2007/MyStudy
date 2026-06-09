### 解题思路

我只能说是被逼的，C语言数组不能直接赋值，而且还没有动态数组，一想到要写两个for循环，内存的申请和释放就头大。。。

具体原理就是多定义几个值代表不同的变化过程。具体的定义参加程序的注释部分吧。


### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    int pos[8][2]=
    {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1},{1,0},  {1,1}
    };

    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            int x,y,livecount=0;
            
            if(board[i][j]==1)
            {
                for(int k=0;k<8;k++)
                {                
                    x=i+pos[k][0];
                    y=j+pos[k][1];
                    if(x>=0&&y>=0&&x<boardSize&&y<*boardColSize)
                    {
                        if(board[x][y]%2==1)
                        {
                            livecount++;
                        }
                    }
                }
                //printf("board[%d][%d]=%d livecount=%d\n",i,j,board[i][j],livecount);
                if(livecount<2||livecount>3)
                {
                    board[i][j]=3;
                }
                else
                {
                    board[i][j]=5;
                }
            }
            else
            {
                for(int k=0;k<8;k++)
                {                
                    x=i+pos[k][0];
                    y=j+pos[k][1];
                    if(x>=0&&y>=0&&x<boardSize&&y<*boardColSize)
                    {
                        if(board[x][y]%2==1)
                        {
                            livecount++;
                        }
                    }
                }
                //printf("board[%d][%d]=%d livecount=%d\n",i,j,board[i][j],livecount);
                if(livecount==3)
                {
                    board[i][j]=2;
                }
                else
                {
                    board[i][j]=4;
                }
            }
        }
    } 
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            if(board[i][j]==3||board[i][j]==4)
            {
                board[i][j]=0;
            }
            else
            {
                board[i][j]=1;
            }
        }
    }
}
/*

1-->0=3
1-->1=5
0-->1=2
0-->0=4

*/
```