方法一，最普通常规的动态规划
时间复杂度O(n^2)，空间复杂度O(n^2)
```cpp
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> res(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
		}
		return res[m - 1][n - 1];
	}
};
```
方法二，动态规划dp数组压缩至一维
时间复杂度O(n^2)，空间复杂度O(n)
```cpp
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};
```
方法三，抽象成数学模型，求C(m+n-2)(m-1)
时间复杂度O(n)，空间复杂度O(1)
```cpp
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		double sum = 1;
		for (int i = 1; i < m; ++i)
		{
			sum *= (i + n - 1);
			sum /= i;
		}
		return int(sum);
	}
};
```