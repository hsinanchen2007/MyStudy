### 思路
1. 扫描矩阵的四个边，如果遇到‘O’则进行DFS，将所有相连接的‘O’替换为某个字符（‘$’）。则最后剩下的‘O’都被‘X’包围。
2. 再次扫描矩阵，将原先的‘$’替换为‘O’，遇到‘O’则替换为‘X’。
### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O') dfs(board, i - 1, j);
            if (i < board.size() - 1 && board[i + 1][j] == 'O') dfs(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O') dfs(board, i, j - 1);
            if (j < board[0].size() - 1 && board[i][j + 1]) dfs(board, i, j + 1);
        }
    }
};
```