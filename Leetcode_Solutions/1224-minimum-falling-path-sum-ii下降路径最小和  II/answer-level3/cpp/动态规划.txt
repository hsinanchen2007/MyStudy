### 解题思路
### 代码

```cpp
class Solution {
public:
    int maxm=static_cast<int>(pow(2,31)-1);
    int minFallingPathSum(vector<vector<int>>& arr) {
        int w = arr[0].size();
	int h = arr.size();
	int**dp = new int*[h];
	for (int i = h-1; i >=0; i--)
	{
		dp[i] = new int[w];
		if(i!=h-1)
		for (int j = 0; j < w; j++)
		{
			int min = maxm;
			for (int k = 0; k < w; k++)
			{
				if (k == j)
					continue;
				else
				{
					if (dp[i + 1][k] < min)
						min = dp[i + 1][k];
				}
			}
			dp[i][j] = min+arr[i][j];
		}
		else
		{
			for (int j = 0; j < w; j++)
				dp[i][j] = arr[i][j];
		}
	}
	int min = maxm;
	for (int i = 0; i < w; i++)
		if (min > dp[0][i])
			min = dp[0][i];
	return min;
    }
};
```