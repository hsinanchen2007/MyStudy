### 解题思路
同时计算要求之前改变的数组值不能影响到之后的数组，所以可以这样设计：1->0的替换为1->2；0->1的替换为0->-1；后面元素在判断周围活细胞个数的时候直接把2当成1即可；
完成第一遍遍历之后需要再一次进行遍历将2改为0、-1改为1；

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    if(!board)
        return;
    int di[8]={0,0,1,-1,1,-1,1,-1};
    int dj[8]={1,-1,0,0,1,-1,-1,1};
    int tempi=0,tempj=0;

    for(int i=0;i<boardSize;++i)
    {
        for(int j=0;j<boardColSize[i];++j)
        {
            if(board[i][j]==1)
            {
                int live=0;
                for(int k=0;k<8;++k)
                {
                    tempi=i+di[k];
                    tempj=j+dj[k];
                    if(tempi>=0&&tempi<boardSize&&tempj>=0&&tempj<boardColSize[i])
                    {
                        if(board[tempi][tempj]==1||board[tempi][tempj]==2)
                            live++;
                    }
                }
                if(live<2||live>3)
                {
                    board[i][j]=2;
                }
            }

            if(board[i][j]==0)
            {
                int live=0;
                for(int k=0;k<8;++k)
                {
                    tempi=i+di[k];
                    tempj=j+dj[k];
                    if(tempi>=0&&tempi<boardSize&&tempj>=0&&tempj<boardColSize[i])
                    {
                        if(board[tempi][tempj]==1||board[tempi][tempj]==2)
                            live++;
                    }    
                }
                if(live==3)
                    board[i][j]=-1;
            }
        }
    }
    for(int i=0;i<boardSize;++i)
    {
        printf("第%d行：",i);
        for(int j=0;j<boardColSize[i];++j)
        {
            printf("%d,",board[i][j]);
            if(board[i][j]==2)
                board[i][j]=0;
            if(board[i][j]==-1)
                board[i][j]=1;
        }
        printf("\n");
    }

    return;

}
```