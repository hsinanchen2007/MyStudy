
### 代码

```cpp
class Solution {
public:
    int getArea(vector<vector<int>>& grid, int i, int j)
    {
        if(i == grid.size() || i < 0 || j == grid[0].size() || j < 0) return 0;
        if(grid[i][j] == 1)
        {
            grid[i][j] = 0;
            return 1 + getArea(grid, i+1, j) + getArea(grid, i-1, j) + getArea(grid, i, j+1)                          + getArea(grid, i, j-1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, maxArea = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) area = getArea(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
```