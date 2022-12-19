### 解题思路
代码很简单 一看就会
### 代码

```cpp
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (i == 0 && j > 0)
				{
					grid[i][j] += grid[i][j - 1];
				}
				else if (j == 0 && i > 0)
				{
					grid[i][j] += grid[i - 1][j];
				}
				else if(i != 0 && j != 0)
				{
					grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
				}
			}
		}
		return grid[rows - 1][cols - 1];
	}
};
```