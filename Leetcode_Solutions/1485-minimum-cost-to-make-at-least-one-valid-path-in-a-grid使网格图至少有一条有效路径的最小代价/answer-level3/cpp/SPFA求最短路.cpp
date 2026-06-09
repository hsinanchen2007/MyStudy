### 解题思路
SPFA求最短路

### 代码

```cpp
class Solution {
public:
    const int N = 100100;
    int dist[110][110];
    bool st[110][110];
    int n, m;
    int spfa(vector<vector<int>> & grid)
    {
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        dist[0][0] = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        st[0][0] = true;

        while (q.size())
        {
            auto t = q.front();
            q.pop();

            int xx = t.first, yy = t.second;

            st[xx][yy] = false;
            for (int i = 0; i < 4; i ++ )
            {
                int x = xx + dx[i], y = yy + dy[i];
                if (x >=0 && x < n && y >=0 && y < m)
                {
                    bool flag = false;
                    if (i + 1 == grid[t.first][t.second]){
                        if (dist[x][y] > dist[t.first][t.second])
                        {
                            dist[x][y] = dist[t.first][t.second];
                            flag = true;
                        }
                    }else{
                        if (dist[x][y] > dist[t.first][t.second] + 1)
                        {
                            dist[x][y] = dist[t.first][t.second] + 1;
                            flag = true;
                        }
                    }
                    if (flag && !st[x][y]) 
                    {
                        q.push({x, y});
                        st[x][y] = true;
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int t = spfa(grid);
        return t;
    }
};
```