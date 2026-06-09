### 解题思路
动态规划，创建一个dp二维数组，用于容纳0到i-1的所有子串，然后每次用dp所有的子串与i相并，并添加到dp中，依次循环，添加空集后输出

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> dp = { vector<int>{nums[0]} };
		for (int i = 1; i < nums.size(); i++)
		{
			vector<int> sub{ nums[i] };
			int len = dp.size();
			for (int j = 0; j < len; j++)
			{
				vector<int> temp = dp[j];
				temp.push_back(nums[i]);
				dp.push_back(temp);
			}
			dp.push_back(sub);
		}
		dp.push_back(vector<int>{});
		return dp;
	}
	
};
```