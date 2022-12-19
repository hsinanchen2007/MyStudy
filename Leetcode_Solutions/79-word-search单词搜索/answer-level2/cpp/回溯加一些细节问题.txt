需要注意的是当遇到[["a", "a"]]和"aa"那就是true。就是在函数退出来的时候需要判断
k == word.size() - 1 ? true : false;因为有可能在最后一个字符发现四周都已经被访问过了，这个时候到达不了word.size()但是且依然匹配。

```cpp
class Solution {
private:
    bool dfs(int i, int j, int k, bool* vis, string& word, 
        vector<vector<char>>& board) {
            if (k == word.size()) return true;
            if (board[i][j] != word[k]) return false;
            int n = board.size(), m = board[0].size();
            vis[i * m + j] = true;
            static int dx[] = {-1, 1, 0, 0};
            static int dy[] = {0, 0, -1, 1};
            for (int d = 0; d < 4; d ++) {
                int x = i + dx[d], y = j + dy[d];
                if (0 <= x && x < n && 0 <= y && y < m && 
                    !vis[x * m + y] && dfs(x, y, k + 1, vis, word, board))
                    return true;
            }
            vis[i * m + j] = false;
            return k == word.size() - 1 ? true : false;
        }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        int n = board.size(), m = board[0].size();
        bool vis[n * m];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j ++) {
                if (word[0] == board[i][j] && dfs(i, j, 0, vis, word,board))
                return true;
            }
        return false;
    }
};