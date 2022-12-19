### 解题思路
此处撰写解题思路
rt
### 代码

```c
//初始化， 棋子为‘X’的老父亲设为-2，棋盘边缘棋子为‘O’且的老父亲设为-1，棋盘内棋子为‘O’的老父亲设为自己，
void init(char **board, int boardSize, int *boardColSize, int *fa, int len)
{  
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j < boardColSize[i]; j++)
        {
            int size = i * boardColSize[i] + j;;
 
            if(board[i][j] == 'X')
            {
                fa[size] = -2;     
            }
            else
            {
                if((i == 0) || (i == (boardSize - 1)) || (j == 0) || j == (boardColSize[i] - 1))
                {
                    fa[size] = -1;
                }
                else
                {
                    fa[size] = size;
                }
            }
        }
    }
}
//老父亲<0直接返回，大于等于0则认为是棋盘内的棋子
int find(int x, int *fa, int len)
{
    if(fa[x] < 0)
    {
        return fa[x];
    }
    return x == fa[x]? x : (fa[x] = find(fa[x], fa, len));
}

void merge(int i , int j, int *fa, int len)
{
    int x = find(i, fa, len);
    int y = find(j, fa, len);

    if(x==-1 || y == -1)  //把老祖宗设为边缘棋子
    {
        if(x==y)
        {
            return;
        }
        if(x==-1)
        {
            fa[find(j, fa, len)] = -1;
        }
        if(y ==-1)
        {
            fa[find(i, fa, len)] = -1;
        }
    }
    else
    {
        fa[find(j, fa, len)] = i; //把上个棋子设为自己儿子
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    if(board == NULL || boardSize <= 0)
    {
        return;
    }
    int len = boardSize * boardColSize[0];
    int fa[len];           
    init(board, boardSize, boardColSize, &fa, len);
    for(int i = 1; i < boardSize; i++)
    {
        for(int j = 1; j < boardColSize[i]; j++)
        {
            if(board[i][j] == 'O')
            {
                int size = i * boardColSize[i] + j;
                if(board[i][j-1] == 'O')
                {
                    merge(size, size - 1, &fa, len);
                }
                if(board[i-1][j] == 'O')
                {
                    merge(size, size - boardColSize[i-1], &fa, len);
                }                   
            }
        }
    }
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardColSize[i]; j++)
        {
            int size = i * boardColSize[i] + j;
            if(find(size, fa, len) >= 0)     //老祖宗不为-1则认为是棋盘内的棋子
            {
                board[i][j] = 'X'; 
            }
        }
    }
}
```