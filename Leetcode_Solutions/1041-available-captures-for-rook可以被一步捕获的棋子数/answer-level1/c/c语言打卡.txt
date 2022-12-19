### 解题思路
四个for

### 代码

```c
void catchRook(char** board, int boardSize, int* boardColSize, int* r, int* c){
    int i, j;
    for(i = 0;i < boardSize;i ++)
        for(j = 0;j < boardColSize[i];j ++)
            if(board[i][j] == 'R'){
                *r = i;
                *c = j;
                return;
            }
    *r = -1;
    *c = -1;
}

int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i, x, y, num = 0;
    catchRook(board, boardSize, boardColSize, &x, &y);
    for(i = x;i < boardSize && y < boardColSize[i];i ++)
        if(board[i][y] == 'p'){
            num ++;
            break;
        }
        else if(board[i][y] == 'B')
            break;
    for(i = x;i >= 0 && y < boardColSize[i];i --)
        if(board[i][y] == 'p'){
            num ++;
            break;
        }
        else if(board[i][y] == 'B')
            break;
    for(i = y;i < boardColSize[x];i ++)
        if(board[x][i] == 'p'){
            num ++;
            break;
        }
        else if(board[x][i] == 'B')
            break;
    for(i = y;i >= 0;i --)
        if(board[x][i] == 'p'){
            num ++;
            break;
        }
        else if(board[x][i] == 'B')
            break;
    return num;
}
```