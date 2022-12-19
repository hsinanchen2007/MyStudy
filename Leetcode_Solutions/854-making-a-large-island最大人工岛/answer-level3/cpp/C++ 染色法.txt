直观解法：详解见代码注释
```
class Solution {
public:
    int neighbor[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >=0 && c < C;
    }
    void dfs(vector<vector<int> >& grid, int r, int c, int n) {
        if (grid.empty() || n == 0 || n == 1)
            return;
        int R = grid.size();
        int C = grid[0].size();
        if (!valid(r, c, R, C) || grid[r][c] != 1)
            return;
        grid[r][c] = n;
        for (int i = 0; i < 4; ++i) {
            int r1 = r + neighbor[i][0];
            int c1 = c + neighbor[i][1];
            if (valid(r1, c1, R, C) && grid[r1][c1] == 1)
                dfs(grid, r1, c1, n);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int R = grid.size();
        int C = grid[0].size();
        // assign every island with a number n (n > 1)
        // 将每个联通的岛屿都染上同一个数字n，这个数是大于1的数
        int n = 2;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, n);
                    ++n;
                }
            }
        }
        // find candidates and 
        // accumulate the area of every island
        // 寻找候选的海洋色块（邻点中至少有一个陆地），并计算每一个岛屿的面积
        set<pair<int,int> > candidates;
        map<int, int> island_area;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // cout << i << " " << j << " " << grid[i][j] << endl;
                if (grid[i][j] > 0) {
                    ++island_area[grid[i][j]];
                } else {
                    for (int k = 0; k < 4; ++k) {
                        int r = i + neighbor[k][0];
                        int c = j + neighbor[k][1];
                        if (valid(r, c, R, C) && grid[r][c] > 0) {
                            candidates.insert({i, j});
                            break;
                        }
                    }
                }
            }
        }
        if (island_area.empty())
            return 1;
        if (candidates.size() <= 1)
            return R * C;
        // search the final result
        // 搜索最终结果
        int res = 0;
        for (auto& p : candidates) {
            int r = p.first;
            int c = p.second;
            int area = 1;
            set<int> islands;
            for (int k = 0; k < 4; ++k) {
                int r1 = r + neighbor[k][0];
                int c1 = c + neighbor[k][1];
                if (valid(r1, c1, R, C) && grid[r1][c1] > 0) {
                    islands.insert(grid[r1][c1]);
                }
            }
            for (auto k : islands)
                area += island_area[k];
            if (area > res)
                res = area;
        }
        return res;
    }
};
```
