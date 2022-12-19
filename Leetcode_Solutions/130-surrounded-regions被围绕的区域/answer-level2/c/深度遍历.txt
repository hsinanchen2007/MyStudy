1）从矩阵边界往矩阵内部遍历，所有和边界联通的O全部改写为特殊字符A
2）遍历矩阵，把O全部改写成X，A全部改写成O

void BFS(char **s, int i, int j, int low, int col)
{
    if ((i >= low) || (j >= col) || (i < 0) || (j < 0) || (s[i][j] != 'O')) {
        return;
    }

    s[i][j] = 'A';

    BFS(s, i - 1, j, low, col);  // 上
    BFS(s, i + 1, j, low, col);  // 下
    BFS(s, i, j - 1, low, col);  // 左
    BFS(s, i, j + 1, low, col);  // 右
}

void solve(char **board, int boardSize, int *boardColSize)
{
    int i, j, low, col;

    if (boardSize == 0) {
        return;
    }
    low = boardSize;
    col = boardColSize[0];

    // 遍历找出所有和边界联通的O，全部改写为特殊字符A
    // 从上下行边界遍历
    for (i = 0; i < col; i++) {
        if (board[0][i] == 'O') {
            BFS(board, 0, i, low, col);
        }

        if (board[low - 1][i] == 'O') {
            BFS(board, low - 1, i, low, col);
        }
    }
    // 从左右列边界遍历
    for (i = 1; i < low - 1; i++) {
        if (board[i][0] == 'O') {
            BFS(board, i, 0, low, col);
        }

        if (board[i][col - 1] == 'O') {
            BFS(board, i, col - 1, low, col);
        }
    }

    // 遍历矩阵，把O全部改写成X，A全部改写成O
    for (i = 0; i < low; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
        }
    }
}