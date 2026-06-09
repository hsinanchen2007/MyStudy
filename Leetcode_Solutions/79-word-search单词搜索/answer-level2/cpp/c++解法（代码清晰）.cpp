```
class Solution {
private:
    vector<vector<int>> dir;
    bool _checkOnePoint(vector<vector<char>> &board, string &word, const int pos, const int row, const int col) {
        if (pos == word.size())
            return true;
        
        for (int i = 0; i < dir.size(); ++i) {
            int x = row + dir[i][0];
            int y = col + dir[i][1];

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[pos]) {
                char t = board[x][y];
                board[x][y] = 0;
                bool rc = _checkOnePoint(board, word, pos + 1, x, y);
                board[x][y] = t;
                if (rc)
                    return true;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.size() == 0)
            return false;

        dir ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int R = board.size();
        int C = board[0].size();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == word[0]) {
                    char t = board[i][j];
                    board[i][j] = 0;
                    bool rc = _checkOnePoint(board, word, 1, i, j);
                    board[i][j] = t;
                    if (rc)
                        return true;
                }
            }
        }
        return false;
    }
};
```
