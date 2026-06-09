### 解题思路
    /*
     * 深度优先遍历(DFS)
     *
     * 由于在矩阵边界的字符O不能被转化，且与其相连的O也不能被转化，
     * 所以需要将与边界的字符O相连的字符O特殊对待。
     * 可以先使用深度优先遍历找出与边界字符O相连的O，并将它们转化为字符#。
     * 深度优先遍历时，先在边界找到字符O，将其修改为字符#，
     * 再从该点对其上下左右的点进行判断是否为相连的字符O，如果是则修改为#。
     * 将与边界O相连的O包括边界的O全部转化为#后，对矩阵重新进行遍历。
     * 将矩阵中不与边界O相连的字符O转化为字符X,将字符#转化为字符O。
     * */
### 代码

```cpp
void solve(std::vector<std::vector<char>> &board) {
    if (board.empty()) {
        return;
    }

    int rows = board.size();
    int cols = board[0].size();

    if (rows == 0 || cols == 0) {
        return;
    }

    // 第一次遍历矩阵，找与边界O相连的字符O
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 是否在矩阵边界上
            bool isEdge = (i == 0) || (j == 0) || (i == rows - 1) || (j == cols - 1);
            // 对矩阵边界上的字符O进行递归处理
            if (isEdge && board[i][j] == 'O') {
                dfs(board, i, j);
            }
        }
    }

    // 第二次遍历矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 找到矩阵中的字符O转换为字符X
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }

            // 将字符#还原为字符O
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

void dfs(std::vector<std::vector<char>> &board, int x, int y) {
    // 如果超出范围或是字符X或是字符#，则递归函数直接返回
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == 'X' || board[x][y] == '#') {
        return;
    }

    // 如果是相连的字符O，则转换为字符#
    board[x][y] = '#';

    // 对相连的字符O的上下左右进行递归判断并修改
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
}
```