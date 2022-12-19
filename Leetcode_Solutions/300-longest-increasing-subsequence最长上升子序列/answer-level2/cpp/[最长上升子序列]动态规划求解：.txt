### 解题思路

动态规划求解：
状态方程：dp[i]
状态转移方程：dp[i]=dp[j]+1,dp[j]表示小于[i]的所有最优子结构

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n<=0)
        return 0;
	vector<int> dp;
	for (int i = 0; i < n; i++)
		dp.push_back(1);
	int maxL = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j])
				dp[i] = dp[i]>(dp[j] + 1)?dp[i]:(dp[j] + 1);
		maxL = maxL > dp[i] ? maxL : dp[i];
	}
	return maxL;
    }
};
```