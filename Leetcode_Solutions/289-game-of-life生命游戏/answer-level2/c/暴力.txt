### 解题思路
快乐小白的暴力遍历 遍历每个节点的8个方向  

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(boardColSize[0]==0)
    return ;
    int a[boardSize][boardColSize[0]];
    int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    int i=0,j=0,z;
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[0];j++)
        {
            a[i][j]=0;
        }
    }

   
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[i];j++)
        {
            int k=0;
            for(z=0;z<8;z++)
            {
                int x=i+dir[z][0];
                int y=j+dir[z][1];
                if(x<0||y<0||x>=boardSize||y>=boardColSize[0])
                {
                    continue;
                }
                if(board[x][y]==1)
                    k++;
            }
            if(k<2)
                a[i][j]=0;
            if(board[i][j]==1&&k>=2&&k<=3)
                a[i][j]=1;
            if(board[i][j]==1&&k>3)
                a[i][j]=0;
            if(k==3)
                a[i][j]=1;
        }
    }
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[0];j++)
        {
            board[i][j]=a[i][j];
        }
    }
}
```