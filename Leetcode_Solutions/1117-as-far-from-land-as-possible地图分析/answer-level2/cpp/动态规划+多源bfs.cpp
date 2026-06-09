### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //dp解法
    int dpSearch(vector<vector<int>>& grid)
    {
        const int N = grid.size();
        const int INF = 200;
        int ans = -1;
        vector<vector<int>> dp(N, vector(N, INF));
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++)
            {
                if(grid[r][c]) dp[r][c] = 0;
                else dp[r][c] = min(r > 0 ? dp[r-1][c] : INF, c > 0 ? dp[r][c-1] : INF) + 1;
            }
        for(int r = N - 1; r >= 0; r--)
            for(int c = N - 1; c >= 0; c--)
            {
                if(r + 1 < N) dp[r][c] = min(dp[r][c], dp[r+1][c] + 1);
                if(c + 1 < N) dp[r][c] = min(dp[r][c], dp[r][c+1] + 1);
            } 
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++)
                if(dp[r][c]) ans = max(ans, dp[r][c]);   
        return ans >= INF? -1 : ans;
    }

    //多源bfs
    int bfs(vector<vector<int>>& grid)
    {
        const int N = grid.size();
        const int drct[2][4] = {{-1,1,0,0},{0,0,-1,1}};
        int count = -1;
        queue<pair<int,int>> q;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++)
                if(grid[r][c]) q.push({r,c});

        if(!q.size() || q.size() == N * N) return -1;
        while(!q.empty())
        {
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int nr = r + drct[0][j];
                    int nc = c + drct[1][j];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N || grid[nr][nc]) continue;
                    q.push({nr,nc});
                    grid[nr][nc] = 1;   //为1表示已经访问
                }
            }   
        }
        return count;
    }

    int maxDistance(vector<vector<int>>& grid) {
        //dp解法
        // return dpSearch(grid);

        //多源bfs
        return bfs(grid);
    }
};
```