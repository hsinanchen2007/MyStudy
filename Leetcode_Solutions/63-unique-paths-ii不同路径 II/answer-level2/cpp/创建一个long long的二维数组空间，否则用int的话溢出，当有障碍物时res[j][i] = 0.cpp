### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int  m = obstacleGrid[0].size(), n = obstacleGrid.size(), i, j;
	  if(obstacleGrid[0][0] ==1)
	  return 0;
	  vector<vector<long long>> res(n,vector<long long>(m,0));
	for (i = 0; i < m; i++)
	{
		if (obstacleGrid[0][i] == 0)
			res[0][i] = 1;
		else
		{
			res[0][i] = 0;
			break;
		}
	}
	for (j = 1; j < n; j++)
	{
		if (obstacleGrid[j][0] == 0)
			res[j][0] = 1;
		else
		{
			res[j][0] = 0;
			break;
		}
	}
	for (j = 1; j < n; j++)
	{
		for (i = 1; i < m; i++)
		{
			if (obstacleGrid[j][i] == 1)
				continue;
			else
			{
				res[j][i] = res[j][i - 1] + res[j - 1][i];
			}
		}
	}
	return res[n - 1][m - 1];
    }
};
```