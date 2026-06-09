整体思路和八皇后类似，就是填格子游戏。

- Step.1 在当前格子n填一个数 k，验证是否合理：
- Step.2 如果合理，就填写下一个格子
- Step.3 如果不合理，k = k + 1，进入 Step.1


```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
    bool dfs(vector<vector<char>>& board, int n) {
        if (n >= 81) return true;
        int row = n / 9, col = n % 9;
        if (board[row][col] != '.') return dfs(board, n + 1);
        for (char k = '1'; k <= '9'; ++k) {
            if (check(board, row, col, k)) {
                char c = board[row][col];
                board[row][col] = k;
                if (dfs(board, n + 1)) return true;
                board[row][col] = c;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int i, int j, char k) {
        for (int row = 0; row < 9; ++row) if (board[row][j] == k) return false;
        for (int col = 0; col < 9; ++col) if (board[i][col] == k) return false;
        int x = i / 3 * 3,y = j / 3 * 3;
        for (int row = x; row < x + 3; ++row)
            for (int col = y; col < y + 3; ++col) if (board[row][col] == k) return false;
        return true;
    }
};
```

下面是展开的代码：

```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
    
    bool dfs(vector<vector<char>>& board, int n) {
        if (n >= 81) {
            return true;
        }
        
        int row = n / 9;
        int col = n % 9;
        
        if (board[row][col] != '.') {
            return dfs(board, n + 1);
        }
        
        for (char k = '1'; k <= '9'; ++k) {
            if (check(board, row, col, k)) {
                char c = board[row][col];
                board[row][col] = k;
                if (dfs(board, n + 1)) return true;
                board[row][col] = c;
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, char k) {
        for (int row = 0; row < 9; ++row) {
            if (board[row][j] == k) return false;
        }
        for (int col = 0; col < 9; ++col) {
            if (board[i][col] == k) return false;
        }
        
        int x = i / 3 * 3;
        int y = j / 3 * 3;
        for (int row = x; row < x + 3; ++row) {
            for (int col = y; col < y + 3; ++col) {
                if (board[row][col] == k) return false;
            }
        }
        return true;
    }
};
```
