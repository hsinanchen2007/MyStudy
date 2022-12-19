### 解题思路
先找到车的位置，然后搜索车上下左右的四个方向，遇到卒将 count++ 退出搜索，遇到象直接退出搜索，最后返回count

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int count = 0;
    // 找到车的位置并记录i j 的值
    int a = 0,b = 0;
    int m = 0,n = 0;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardColSize[i]; j++)
        {
            if(board[i][j] == 'R')
            {
                a = i;
                b = j;
            }
        }
    }

    m = a;
    n = b;
    while(1)
    {
        n--;
        if(n >= 0)
        {
            if(board[m][n] == 'p') 
            {
                count++;
                break;
            }
            else if(board[m][n] == 'B') break;
        }
        else break;
    }

    m = a;
    n = b;
    while(1)
    {
        m--;
        if(m >= 0)
        {
            if(board[m][n] == 'p') 
            {
                count++;
                break;
            }
            else if(board[m][n] == 'B') break;
        }
        else break;
    }

    m = a;
    n = b;
    while(1)
    {
        n++;
        if(n < boardColSize[m])
        {
            if(board[m][n] == 'p') 
            {
                count++;
                break;
            }
            else if(board[m][n] == 'B') break;
        }
        else break;
    }

    m = a;
    n = b;
    while(1)
    {
        m++;
        if(m < boardSize)
        {
            if(board[m][n] == 'p') 
            {
                count++;
                break;
            }
            else if(board[m][n] == 'B') break;
        }
        else break;
    }

    return count;
}
```