![image.png](https://pic.leetcode-cn.com/df4ce9ad5d0f47d318977021025ae9019f3e9d011dd217941afdf1a7c15f21de-image.png)

```
//增加中间态：当前存活，下阶段死亡： 2
//增加中间态：当前死亡，下阶段存活： 3
//遍历数组1次：得到中间态。
//遍历数组2次：得到最终态。

int xMax = 0;
int yMax = 0;

int getNowPointState(int **board, int x, int y){
    if((x < 0) || (x >= xMax)){
        return 0;
    }
    if((y < 0) || (y >= yMax)){
        return 0;
    }
    if(board[x][y] == 2){
        return 1;
    }
    if(board[x][y] == 3){
        return 0;
    }
    return board[x][y];
}

void getNextPointState(int **board, int x, int y){
    int aroundLive = 0;
    int nowState = board[x][y];
    int nextState;
    
    for(int i = x - 1; i <= x + 1; i++){
        for(int j = y - 1; j <= y + 1; j++){
            aroundLive += getNowPointState(board, i, j);
        }
    }
    aroundLive -= nowState;

    if((nowState == 0) && (aroundLive == 3)){
        nextState = 3;
    } else if((nowState == 1) && (aroundLive != 2) && (aroundLive != 3)){
        nextState = 2;
    }else{
        nextState = nowState;
    }
    board[x][y] = nextState;
}

void getMidState(int **board){
    for(int i = 0; i < xMax; i++){
        for(int j = 0; j < yMax; j++){
            getNextPointState(board, i, j);
        }
    }
}

void getFinalState(int **board){
    for(int i = 0; i < xMax; i++){
        for(int j = 0; j < yMax; j++){
            if(board[i][j] == 2){
                board[i][j] = 0;
            }else if(board[i][j] == 3){
                board[i][j] = 1;
            }
        }
    }
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    xMax = boardSize;
    yMax = *boardColSize;
    getMidState(board);
    getFinalState(board);

}
```
