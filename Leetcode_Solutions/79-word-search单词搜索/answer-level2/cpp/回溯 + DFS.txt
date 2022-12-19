### 解题思路

Visited数组只用来防止走回头路。

执行用时 :88 ms

### 代码

```cpp
class Solution {
private:
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int m;
    int n;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(m == 0)
            return false;
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && !visited[i][j]) {
                    if(dfs(i, j, board, word, 0))
                        return true;
                    visited.assign(m, vector<bool>(n, false));
                    // cout << endl;
                }
            }
        return false;
    }
    
    bool dfs(int x, int y, vector<vector<char>>& board, string& word, int j) {
        // cout << board[x][y];
        if(j == word.size() - 1)
            return true;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            if(nx < 0 || nx > m - 1)
                continue;
            int ny = y + dy[i];
            if(ny < 0 || ny > n - 1)
                continue;
            if(board[nx][ny] != word[j+1] || visited[nx][ny])
                continue;
            visited[x][y] = true;
            if(dfs(nx, ny, board, word, j+1))
                return true;
            visited[x][y] = false;
        }
        return false;
    }
};
```