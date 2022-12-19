### 解题思路
没难点，就是方向数组，注意别把本身的坐标给计算进去

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    //方向数组
    int dir_x[8]={-1,-1,-1,0,0,1,1,1};
    int dir_y[8]={-1,0,1,-1,1,-1,0,1};

    //建立中间面板
    int **t_board=(int **)malloc(sizeof(int *)*boardSize);
    int i;
    for(i=0;i<boardSize;i++)
    t_board[i]=(int *)malloc(sizeof(int)*(*boardColSize));

    int j,k;
    for(i=0;i<boardSize;i++)//x坐标
    {
        for(j=0;j<*boardColSize;j++)//y坐标
        {
            int live=0;//记录生存和死亡的细胞数目
            for(k=0;k<8;k++)//加载新的坐标
            {
                int new_x=i+dir_x[k];
                int new_y=j+dir_y[k];
                if(new_x>=0&&new_x<boardSize&&new_y>=0&&new_y<*boardColSize)//符合要求
                {
                    if(board[new_x][new_y]==1)live++;
                }
            }
            if(live<2||live>3)t_board[i][j]=0;
            else if(live==3)t_board[i][j]=1;
            else if((live==2||live==3)&&board[i][j]==1)t_board[i][j]=1;//这里的两个或的括号别落下
            else if((live==2||live==3)&&board[i][j]==0)t_board[i][j]=0;
        }
    }

for(i = 0; i < boardSize; i ++)
for(j = 0; j < *boardColSize; j ++)
board[i][j] = t_board[i][j];//逐元素赋值。
   // memcpy(board,t_board,sizeof(t_board));
}

```