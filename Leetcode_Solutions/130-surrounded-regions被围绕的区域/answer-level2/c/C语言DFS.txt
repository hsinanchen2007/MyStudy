bool IsEdge(int i, int j, int boardSize, int* boardColSize)
{
    if (i == 0 || i == boardSize - 1 || j == 0 || j == *boardColSize - 1) {
        return true;
    } else {
        return false;
    }
}

void Dfs(char** board, int boardSize, int* boardColSize, int i, int j)
{
    if (i < 0 || i >= boardSize || j < 0 || j >= *boardColSize || board[i][j] == 'X' || board[i][j] == '#') {
        // board[i][j] == '#' 说明已经搜索过了
        return;
    }

    board[i][j] = '#';
    // 上
    Dfs(board, boardSize, boardColSize, i - 1, j);
    // 下
    Dfs(board, boardSize, boardColSize, i + 1, j);
    // 左
    Dfs(board, boardSize, boardColSize, i, j - 1);
    // 右
    Dfs(board, boardSize, boardColSize, i, j + 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize == 0 || boardColSize == NULL) {
        return;
    }

    int i, j;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            // 从边缘'O'开始搜索, 跟边缘'O'连通的都是不符合的，都替换为‘#’
            if (IsEdge(i, j, boardSize, boardColSize) == true && board[i][j] == 'O') {
                Dfs(board, boardSize, boardColSize, i, j);
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }

            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}