### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size());//dp数组大小
		//边界
		dp[0] = nums[0];
		//状态转移
		for (int i=1;i<nums.size();i++)
		{
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
		}
		//求出最大值
		vector<int>::iterator myMax = max_element(dp.begin(), dp.end());
		return *myMax;
	}
};
```