```
int r, c;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int ans = 0;
        r = matrix.size() - 1, c = matrix[0].size() - 1;
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
        for(int i = 0; i <= r; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>> &dp)
    {
        if(dp[x][y]) return dp[x][y];
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        bool isOk = true;
        for(int i = 0; i < 4; i++)
        {
            int cx = dx[i] + x, cy = dy[i] + y;
            if(cx < 0 || cx > r || cy < 0 || cy > c || matrix[x][y] >= matrix[cx][cy]) continue;
            dp[x][y] = max(dp[x][y], dfs(matrix, cx, cy, dp) + 1);
            isOk = false;
        }
        if(isOk) dp[x][y] = 1;
        return dp[x][y];
    }
```
