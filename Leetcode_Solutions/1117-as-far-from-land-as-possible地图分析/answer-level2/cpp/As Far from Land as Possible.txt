### 解题思路
As Far from Land as Possible

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    que.push(make_pair(i, j));
                }
            }
        }
        if (que.empty() || que.size() == n * n) return -1;
        pair<int, int> cur;
        while (!que.empty()) 
        {
            cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) 
            {
                int r_ = cur.first + dirs[i][0];
                int c_ = cur.second + dirs[i][1];
                if (r_ >= 0 && r_ < n && c_ >= 0 && c_ < n && grid[r_][c_] == 0) {
                    grid[r_][c_] = grid[cur.first][cur.second] + 1;
                    que.push(make_pair(r_, c_));
                }
            }
        }
        return grid[cur.first][cur.second] - 1;

    }
};
```