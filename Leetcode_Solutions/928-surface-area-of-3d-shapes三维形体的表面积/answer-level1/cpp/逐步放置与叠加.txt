假设刚开始每一个座标处都为空，按照 i = 0 --> grid.size(), j = 0 --> grid[i].size() 的方式依次放入对应的六面体。
首先把每一个坐标处的六面体的表面积累加，增量为 2 + 4*grid[i][j]。
把六面体放入当前座标处(i, j)，会与之前放置的六面体之间产生重叠，导致有些表面被遮挡。
会产生重叠的坐标为(i - 1, j) 与 (i, j - 1)，重叠的面积为 2*min(grid[i][j], grid[x][y])


```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == 0)continue;
                ans += 2 + 4*grid[i][j];
                if(i > 0)ans -= 2*min(grid[i][j], grid[i-1][j]);
                if(j > 0)ans -= 2*min(grid[i][j], grid[i][j-1]);
            }
        }
        return ans;
    }
};
```