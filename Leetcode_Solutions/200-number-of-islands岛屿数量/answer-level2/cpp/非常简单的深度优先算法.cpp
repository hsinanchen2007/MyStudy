### 解题思路
非常简单的深度优先算法

### 代码

```cpp
class Solution {
public:
   vector<pair<int,int> >dirs{ { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

    void dfs(vector<vector<char>>& a, int x, int y) {
        if (x < 0 || y < 0 || x >= a.size() || y >= a[0].size() || a[x][y] == '0')	return;
        a[x][y] = '0';
        for (auto move : dirs) {
            dfs(a, x + move.first, y + move.second);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans += 1;
                }
            }
        }
        return ans;
    }

};
```