```
static void DFS(char** board, int boardSize, int* boardColSize, int i, int j)
{
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[0]) {
        return;
    }
    if (board[i][j] != 'O') {
        return;
    }
    board[i][j] = 'A';
    DFS(board, boardSize, boardColSize, i, j + 1);
    DFS(board, boardSize, boardColSize, i + 1, j);
    DFS(board, boardSize, boardColSize, i, j - 1);
    DFS(board, boardSize, boardColSize, i - 1, j);
}

void solve(char** board, int boardSize, int* boardColSize){
    int i, j;
    int rows = boardSize;
    int cols = boardColSize[0];
    
    if (board == NULL || boardSize == 0 || boardColSize == NULL) {
        return;
    }
    
    for (i = 0; i < cols; i++) {
        DFS(board, boardSize, boardColSize, 0, i);
        DFS(board, boardSize, boardColSize, rows - 1, i);
    }
    for (i = 1; i < (rows - 1); i++) {
        DFS(board, boardSize, boardColSize, i, 0);
        DFS(board, boardSize, boardColSize, i, cols - 1);
    }
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
        }
    }
}
```
