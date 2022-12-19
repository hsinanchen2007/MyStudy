# [岛屿](https://leetcode-cn.com/problems/max-area-of-island/)
## dfs
小优化：不需要用额外的bool数组记录是否访问过，直接将访问过的陆地变为水就可以了。

注意area的计算，每次dfs到下一个点，都要更新area的值并返回给上一个点，这样就能保证dfs入口处返回的area是总的大小

## code
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea = 0;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>> &grid, int row, int col, int area)
    {
        grid[row][col] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nxtRow = row + dir[i][0];
            int nxtCol = col + dir[i][1];
            if (nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
                continue;
            if (grid[nxtRow][nxtCol])
            {
                area = dfs(grid, nxtRow, nxtCol, area + 1);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    maxArea = max(dfs(grid, i, j, 1), maxArea);
                }
            }
        }
        return maxArea;
    }
};
```

## [变式：求岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)
比上一题简单一点，只需要记录dfs了多少次即可，不需要求面积。
```cpp
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
            {
                maxArea = max(dfs(grid, i, j, 1), maxArea);
            }
        }
    }
    return maxArea;
}
```