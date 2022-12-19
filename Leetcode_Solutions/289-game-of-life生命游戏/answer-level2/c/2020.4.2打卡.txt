### 解题思路
用一个二维数组tmp存储更新后的地图，计算完后，再把值赋给原board数组

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(*boardColSize==0)
    {
        return;
    }
    int tmp[boardSize][*boardColSize];
    int stepx[8]={0,0,-1,-1,-1,1,1,1};
    int stepy[8]={-1,1,-1,0,1,-1,0,1};
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            int cntlive=0;
            for(int k=0;k<8;k++)
            {
                int x=i+stepx[k];
                int y=j+stepy[k];
                if(x>=0 && x<boardSize && y>=0 && y<*boardColSize)
                {
                    cntlive+=board[x][y];
                }
            }
           // printf("%d ",cntlive);
            tmp[i][j]=board[i][j];
            if(board[i][j]==1 && (cntlive<2 || cntlive>3))
            {
                tmp[i][j]=0;
            }
            if(board[i][j]==0 && cntlive==3)
            {
                tmp[i][j]=1;
            }
        }
       // printf("\n");
    }

    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            board[i][j]=tmp[i][j];
        }
    }

}
```