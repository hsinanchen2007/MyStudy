### 解题思路
1 从边界的O开始，深搜，讲所有连着的O改为＃；
2 将所有的O改为X，＃改为O；

### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) {
            return;
        }
        int column = board[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                int isBoundary = (i == 0 || j == 0 || i == row-1 || j == column-1);
                if (isBoundary && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for(int i = 0; i < row; ++i) { 
            for(int j = 0; j < column; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }else if (board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = '#';
        if (x-1 >= 0 && board[x-1][y] == 'O') {
            dfs(board, x-1,y);
        }
        if (y-1 >= 0 && board[x][y-1] == 'O') {
            dfs(board, x, y-1);
        }
        if (x+1 < board.size() && board[x+1][y] == 'O') {
            dfs(board, x+1, y);
        }
        if (y+1 < board[0].size() && board[x][y+1] == 'O') {
            dfs(board,x, y+1);
        }
    }
};
```