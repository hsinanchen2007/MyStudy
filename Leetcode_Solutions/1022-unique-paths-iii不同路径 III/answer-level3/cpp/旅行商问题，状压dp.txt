```
int dp[20][1 << 20];
int lable[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> rev[20];
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(dp, 0, sizeof(dp));
        memset(lable, 0, sizeof(lable));
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        int sta = 0, end = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == -1) continue;
                rev[cnt] = {i, j};
                lable[i][j] = cnt++;
                if (grid[i][j] == 1) sta = lable[i][j];
                if (grid[i][j] == 2) end = lable[i][j];
            }
        }
        dp[sta][1 << sta] = 1;
        for (int i = 1; i < (1 << cnt); ++i) {
            for (int j = 0; j < cnt; ++j) {
                if (!((i >> j) & 1) || dp[j][i] == 0) continue;
                for (int k = 0; k < 4; ++k) {
                    int xx = rev[j].first + dx[k];
                    int yy = rev[j].second + dy[k];
                    if (xx < 0 || xx >= row || yy < 0 || yy >= col || grid[xx][yy] == -1) continue;
                    if ((i >> lable[xx][yy]) & 1) continue;
                    dp[lable[xx][yy]][i | (1 << lable[xx][yy])] += dp[j][i];
                } 
            }
        }
        return dp[end][(1 << cnt) - 1];
    }
};
```
