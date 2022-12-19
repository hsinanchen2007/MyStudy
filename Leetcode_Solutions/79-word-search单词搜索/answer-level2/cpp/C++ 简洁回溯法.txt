```
class Solution {
public:
    const static int K = 4;
    int next[K][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool backtrace(vector<vector<char>>& board, int r, int c, string& word, int ind) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || ind >= word.size() ||
                board[r][c] != word[ind])
            return false;
        if (ind == word.size() - 1)
            return true;
        board[r][c] = '#';
        for (int i = 0; i < K; ++i) {
            if (backtrace(board, r + next[i][0], c + next[i][1], word, ind + 1))
                return true;
        }
        board[r][c] = word[ind];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrace(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
```
