### 解题思路
维护一个数组dp，其中数组的下标i代表遍历到当前，长度为i的上升子序列中最后一个数最小是多少。以rst记录dp数组中的元素个数。
每一次遍历一个数组的元素nums[i],如果nums[i]>dp[rst],dp[rst+1]=nums[i],rst++;
如果nums[i]<dp[rst],说明在前面的元素中，需要更新dp的状态，找到nums[i]恰好大于dp中元素的后一位，把这一位的值更新成nums[i].遍历完数组后，返回rst+1就是结果。

### 代码

```cpp
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), INT_MIN);//保存i个长度的子序列的最后一个长度的最小值。
		if (nums.size() == 0) return 0;
		int rst = 0; dp[0] = nums[0];
		for (int i = 1; i<nums.size(); i++)
		{
			if (nums[i]>dp[rst]) dp[++rst] = nums[i];
			else
			{
				dp[division(0, rst, dp, nums[i])] = nums[i];
			}

		}
		return rst+1;
	}

	int division(int left, int right, vector<int> dp, int cur)
	{
		while (left<right)
		{
			int middle = left + (right - left) / 2; //右中位数
			if (dp[middle]<cur)
			{
				left = middle + 1;
			}
			else right = middle;
		}
		return left;
	}
};

```