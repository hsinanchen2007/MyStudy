### 解题思路
一个立方体是6 两个立方体叠加是5 + 5 可以写成6 + 4, 三个立方体是 5 + 5 + 4 可以写成 6 + 4 + 4
就等于 6 + (n - 1) * 4
那么还有被4周覆盖的面 要减去四周的相同的就好啦
例如 [[1,2],
      [3,4]]
和1 相邻的分别是 2 和 3 最小值是1 所以总和 - 2

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;

        int count = 0;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[i].size(); j++)
                if(grid[i][j] != 0)
                {
                    count += 6 + (grid[i][j] - 1) * 4;
                    count -= dfs(grid, i, j + 1, grid[i][j]);
                    count -= dfs(grid, i, j - 1, grid[i][j]);
                    count -= dfs(grid, i + 1, j, grid[i][j]);
                    count -= dfs(grid, i - 1, j, grid[i][j]);
                }
        }

        return count;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int n)
    {
        if(x < 0 || y < 0 || grid[0].size() <= y || grid.size() <= x)
            return 0;

        return grid[x][y] > n ? n : grid[x][y];
    }
};
```