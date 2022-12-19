### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (helper(board, word, i, j, 0)) return true;
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int ni, int nj, int now) {
        if (board[ni][nj] == word[now]) {
            if (now == word.size() - 1) {
                return true;
            }
            char tmp = board[ni][nj];
            board[ni][nj] = '*';
            if (ni + 1 < board.size() && helper(board, word, ni + 1, nj, now + 1)) return true;
            if (ni - 1 >= 0 && helper(board, word, ni - 1, nj, now + 1)) return true;
            if (nj + 1 < board[0].size() && helper(board, word, ni, nj + 1, now + 1)) return true;
            if (nj - 1 >= 0 && helper(board, word, ni, nj - 1, now + 1)) return true;
            board[ni][nj] = tmp;
        }
        return false;
    }
};
```