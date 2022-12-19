### 解题思路
此处撰写解题思路

### 代码

```c

void DFS(char** board, int boardSize, int* boardColSize, int row, int col)
{
    if (row < 0 || row >= boardSize /* 行有效性判断 */
        || col < 0 || col >= *boardColSize) { /* 列有效性判断 */
            return;
        }
    
    if (board[row][col] != 'O') { /* 不是‘O’，不用搜索 */
        return;
    }

    board[row][col] = 'M';  /* 临时修改联通的，代表是全部是O联通的 */
    DFS(board, boardSize, boardColSize, row, col + 1); /* 向左搜索 */
    DFS(board, boardSize, boardColSize, row + 1, col); /* 向上搜索 */
    DFS(board, boardSize, boardColSize, row, col - 1); /* 向右搜索 */
    DFS(board, boardSize, boardColSize, row - 1, col); /* 向下搜索 */
}

void solve(char** board, int boardSize, int* boardColSize){
    if (boardColSize == NULL || board == NULL || boardSize == 0) {
        return;
    }

    int row = boardSize;
    int col = *boardColSize;
    
    for (int i = 0; i < col; i++) {
        DFS(board, boardSize, boardColSize, 0, i); /* 第一行搜索 */
        DFS(board, boardSize, boardColSize, row - 1, i); /* 最后一行搜索 */
    }

    for (int i = 1; i < row - 1; i++) { /* 去掉四个角的点，前面的行搜索已经覆盖，所以从1 搜索到 row - 2 */
        DFS(board, boardSize, boardColSize, i, 0); /* 第一列搜索 */
        DFS(board, boardSize, boardColSize, i, col - 1); /* 最后一列搜索 */
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'M') { /* 把联通的修改为原状态 */
                board[i][j] = 'O';
            }
        }
    }

    return;
}
```