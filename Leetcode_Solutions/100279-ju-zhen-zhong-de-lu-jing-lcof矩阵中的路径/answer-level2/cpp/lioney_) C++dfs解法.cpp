```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> v(m, vector<bool>(n));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, 0, v, word)) return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int level, vector<vector<bool>>& v,string word) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || v[i][j] || board[i][j] != word[level]) {
            return false;
        }
        if(level == word.size() - 1) return true;
        v[i][j] = true;
        bool res = dfs(board, i-1, j, level+1, v, word) ||  dfs(board, i, j-1, level+1, v, word) ||
                   dfs(board, i+1, j, level+1, v, word) || dfs(board, i, j+1, level+1, v, word);
        v[i][j] = false;
        return res;
    }
};
```
