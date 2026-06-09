用动态规划的思想组建模型

dp[i][j] = dp[i-1][j -1]+dp[i-1][j]

即可得出解题思路

```
std::vector<std::vector<int>> CLeetCode_Solution::generate(int numRows)
{
	vector<std::vector<int>> ret;
	if (numRows == 0) return ret;

	for (int i = 0; i < numRows; i++)
	{
		//将第二层vec全部初始化为1，避开处理边界的1
		vector<int> ret_sec(i + 1, 1);
		//从1开始处理，并且不处理最后一个
		for (int j=1; j < i;++j)
			ret_sec[j] = ret[ret.size() - 1][j - 1] + ret[ret.size() - 1][j];
		ret.push_back(ret_sec);
	}
	return ret;
}
```
