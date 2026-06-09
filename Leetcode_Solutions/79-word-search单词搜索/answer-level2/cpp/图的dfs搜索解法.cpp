![leetcode.jpg](https://pic.leetcode-cn.com/beb5f78edbf47a15d02adb38877704e65b287237ab6cb26a55a6267bba309a00-leetcode.jpg)


### 代码

```cpp
class Solution {
public:
    bool dfs(vector<vector<char>> & board, int row, int col, string & word, int index) {
        int maxRow = board.size();
        int maxCol = board[0].size();

        if(index == word.length() - 1) {
            return true;
        }

        //board[row][col] = tolower(board[row][col]);
        board[row][col] = '\n';
        bool rc = false;
        if(row + 1 < maxRow && board[row + 1][col] == word[index + 1]) {
            rc = dfs(board, row + 1, col, word, index + 1);
            if(rc) return true;
        }

        if(row - 1 >= 0 && board[row - 1][col] == word[index + 1]) {
            rc = dfs(board, row - 1, col, word, index + 1);
            if(rc) return true;
        }
        
        if(col + 1 < maxCol && board[row][col + 1] == word[index + 1]) {
            rc = dfs(board, row, col + 1, word, index + 1);
            if(rc) return true;
        }
        
        if(col - 1 >= 0 && board[row][col - 1] == word[index + 1]) {
            rc = dfs(board, row, col - 1, word, index + 1);
            if(rc) return true;
        }
        board[row][col] = word[index];

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(!row) return false;
        int col = board[0].size();

        bool res = false;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0]) {
                    res = dfs(board, i, j, word, 0);
                    if(res == true) return true;
                }
            }
        }

        return false;
    }
};
```