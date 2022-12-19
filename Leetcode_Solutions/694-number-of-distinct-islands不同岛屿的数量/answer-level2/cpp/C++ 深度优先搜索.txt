### 解题思路
1，DFS记录岛屿的轮廓
2，排序去重计算数目

### 代码

```cpp
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int> >& grid, int i, int j, int R, int C, vector<pair<int, int> >& profile) {
        bool is_edge = false;
        for (int k = 0; k < 4; ++k) {
            int r = i + dirs[k][0];
            int c = j + dirs[k][1];
            if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != 1) {
                is_edge = true;
            } else {
                grid[r][c] = 2;
                dfs(grid, r, c, R, C, profile);
            }
        }
        if (is_edge) {
            profile.push_back({i, j});
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<pair<int, int> > > profiles;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int> > profile;
                    dfs(grid, i, j, R, C, profile);
                    for (auto& x : profile) {
                        x.first -= i;
                        x.second -= j;
                    }
                    profiles.push_back(profile);
                }
            }
        }
        sort(profiles.begin(), profiles.end());
        return unique(profiles.begin(), profiles.end()) - profiles.begin();
    }
};
```
![image.png](https://pic.leetcode-cn.com/711818d56a5dae4ad71a13475a1a251c4fd2df7045e7c37ddc478669e30a117d-image.png)
