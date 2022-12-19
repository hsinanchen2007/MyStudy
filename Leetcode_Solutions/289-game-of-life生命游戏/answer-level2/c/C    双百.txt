开始还以为空间复杂度必须O(1)才能100，结果O(m*n)也是100；

有题解空间复杂度是O(1)稍微看了一眼，应该通过将输入的board刚好有32位，分成前16位和后16位（因为答案只有0,1所以用不到那么多位），再通过除，余得到是新board还是旧board的值。（不如直接用1bit的类型，岂不是更省空间？）

所以，我写这题的看点也就是新board多围一圈0，避免特殊角的情况（也是看了别的题解才知道的）

贴上菜鸡的代码：

```
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = *boardColSize;
    //int n = row * col;
    int i = 0, j = 0;
    //为了消减特殊情况，先对原二维数组扩增一圈0
    int copy[row+2][col+2];
    //int **copy = (int **)malloc(sizeof(int) * (row+1)*(col+1));
    while(i<row+2) copy[i][0] = 0,copy[i][col+1]=0,i++;
    while(j<col+2) copy[0][j] = 0,copy[row+1][j]=0,j++;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            copy[i+1][j+1] = board[i][j];
    }
    //根据copy，对原数组进行处理
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            int life = 0;
            life = copy[i][j] + copy[i+1][j] + copy[i+2][j] +
                        copy[i][j+1] + copy[i+1][j+1] + copy[i+2][j+1] +
                            copy[i][j+2] + copy[i+1][j+2] + copy[i+2][j+2];
            life -= board[i][j];
            if(life == 3)
                board[i][j] = 1;
            if(life < 2 || life >3)
                board[i][j] = 0;
        }
    }
}
```

