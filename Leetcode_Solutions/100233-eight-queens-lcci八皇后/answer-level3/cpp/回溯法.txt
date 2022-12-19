### 解题思路
回溯法

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0);
        return res;
    }
    
    void backTrack(vector<string>& board, int row) {
        if(row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for(int col = 0; col < n; col++) {
            if(!isValid(board, row, col)) {
                continue;
            }
            board[row][col] = 'Q';
            backTrack(board, row+1);
            board[row][col] = '.';
        }
    }
    
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
```