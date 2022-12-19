```
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    //首先找到白色车的位置
    int row = 0;
    int col = 0;
    int count = 0;

    for(int i = 0;i < boardSize;i++) {
        for(int j = 0;j < *boardColSize;j++) {
            if(board[i][j] == 'R') {
                row = i;
                col = j;
            }
        }
    }
    //搜索白色车四个方向
    //1.上
    for(int i = row;i >= 0;i--) {
        if(board[i][col] == 'B') {
            break;
        }
        if(board[i][col] == 'p') {
            count += 1;
            break;
        }
    }
    //2.下
    for(int i = row;i < boardSize;i++) {
        if(board[i][col] == 'B') {
            break;
        }
        if(board[i][col] == 'p') {
            count += 1;
            break;
        }
    }
    //3.左
    for(int j = col;j >= 0;j--) {
        if(board[row][j] == 'B') {
            break;
        }
        if(board[row][j] == 'p') {
            count += 1;
            break;
        }
    }
    //4.右
    for(int j = col;j < *boardColSize;j++) {
        if(board[row][j] == 'B') {
            break;
        }
        if(board[row][j] == 'p') {
            count += 1;
            break;
        }
    }
    return count;
}
```
