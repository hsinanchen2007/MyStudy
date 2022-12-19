### 解题思路
思路如下，或者查看官方题解

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //通过计算每个单元格立方体对总表面积的贡献
        //规则1:如果这个单元格有立方体，那顶和底两个面会贡献，+2
        //规则2:计算这个单元格上下左右相对于相邻单元格立方体的相对高度，+小x
        int dr[]{0, 1, 0, -1};
        int dc[]{1, 0, -1, 0};

        int N = grid.size();
        int ans = 0;

        for (int r = 0; r < N; ++r)//N * N 网格
            for (int c = 0; c < N; ++c)
                if (grid[r][c] > 0) {
                    ans += 2;//顶和底
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
                        if (0 <= nr && nr < N && 0 <= nc && nc < N)
                            nv = grid[nr][nc];

                        ans += max(grid[r][c] - nv, 0);
                    }
                }

        return ans;
    }
};
```