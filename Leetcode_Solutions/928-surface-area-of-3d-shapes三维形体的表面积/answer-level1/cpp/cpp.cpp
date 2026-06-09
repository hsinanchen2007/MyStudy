### 解题思路
找规律，每个格子上表面积应该是高度h * 4 + 2,但是四周的格子会影响表面积被遮住。减去四周的高度就行

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] != 0) {
                    ans += grid[i][j] * 4 + 2;
                    for (int k = 0; k < 4; k ++) {
                        int new_x = i + dx[k], new_y = j + dy[k];
                        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
                            int t = min(grid[i][j], grid[new_x][new_y]);
                            ans -= t;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```