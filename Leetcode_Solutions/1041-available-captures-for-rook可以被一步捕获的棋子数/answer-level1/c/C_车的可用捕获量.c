### 解题思路
注意空位置的符号是 . 不是 , 

先查左右再查上下可加速


### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    //找出R在棋盘的位置
    int Rrow,Rcol,GotR=0;
    for(int i=0;i<boardSize&&!GotR;++i)
        for(int j=0;j<boardColSize[i]&&!GotR;++j)
            if(board[i][j]=='R')
            {
                GotR=1;
                Rrow=i;
                Rcol=j;
            }

    int result=0;
    //左边
    for(int i=1;Rcol-i>=0;++i)
        if(board[Rrow][Rcol-i]!='.')
        {
            if(board[Rrow][Rcol-i]=='p')
                ++result;
            break;  
        }
    //右边
   for(int i=1;Rcol+i<boardColSize[Rrow];++i)
        if(board[Rrow][Rcol+i]!='.')
        {
            if(board[Rrow][Rcol+i]=='p')
                ++result;
            break;
        }
    //上边
    for(int i=1;Rrow-i>=0;++i)
        if(board[Rrow-i][Rcol]!='.')
        {
            if(board[Rrow-i][Rcol]=='p')
                ++result;
            break;
        }
    //下边
    for(int i=1;Rrow+i<boardSize;++i)
        if(board[Rrow+i][Rcol]!='.')
        {
            if(board[Rrow+i][Rcol]=='p')
                ++result;
            break;
        }

    return result;
}
```