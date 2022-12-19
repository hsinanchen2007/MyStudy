### 解题思路
先把结果放到sign,然后在给board
### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize) {
    if(boardSize==0 || boardColSize[0]==0) return;
    bool sign[boardSize][boardColSize[0]];
    int live, nx, ny;
    int tar[8][2] = {{1,0},{1,1},{0,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
    for(int x=0; x<boardSize; x++) {
        for(int y=0; y<boardColSize[0]; y++) {
            live = 0;
            for(int n=0; n<8; n++) {
                nx = x+tar[n][0];
                ny = y+tar[n][1];
                if(nx>-1 && ny>-1 && nx<boardSize && ny<boardColSize[0] && board[nx][ny]) {
                    live++;
                    if(live > 3) break;
                }
            }
            if(board[x][y]) {
                if(live==2 || live==3) sign[x][y] = true;
                else sign[x][y] = false;
            } else {
                if(live == 3) sign[x][y] = true;
                else sign[x][y] = false;
            }
        }
    }
    for(int x=0; x<boardSize; x++) for(int y=0; y<boardColSize[0]; y++) board[x][y] = sign[x][y];
}
```