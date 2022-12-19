1. 把二维网格按行优先，排列成一维数组。
    [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
2. 一维数组
    [3,8,1,9,19,7,2,5,4,6,11,10,12,0,21,13]
3. 迁移k次之后
    [12,0,21,13,3,8,1,9,19,7,2,5,4,6,11,10]
4. 这种对二维网格的迁移，实际上是把一维数组循环右移k位。
5. 二维网格grid[r][c]高为m, 宽为n，与一维数组A[i]长度m*n，下标对应关系为 i = r * n + c。
6. 结果 ans[r][c] 对应 grid 的下标为 {((m*n - k + r * n + c) % (m*n))/n, ((m*n - k + r * n + c) % (m*n))%n}。

```c++
class Solution {
public:
    vector<vector<int>> shiftGrid(const vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return grid;
        vector<vector<int>> ans(grid);
        const int m = grid.size(),
                  n = grid[0].size(),
                  sz = m * n;
        k = k % sz;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                const int pos = (sz - k + r * n + c) % sz,
                          nr = pos / n,
                          nc = pos % n;
                ans[r][c] = grid[nr][nc];
            }
        }
        return ans;
    }
};
```
