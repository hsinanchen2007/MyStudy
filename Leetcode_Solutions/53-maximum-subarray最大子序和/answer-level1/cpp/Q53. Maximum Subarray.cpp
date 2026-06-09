### 经典的最大子序列和问题
从前往后扫描数组，同时validSum记录当前“有效的和”。如果validSum大于0，则表示前面计算的和可用，对后面的数字nums[i]有增益，可以加上；否则，validSum小于0时，前面的和应当舍弃，不应该加上，直接将validSum更新为nums[i]。同时更新validSum之后取最大值即为此题解。
```
class Solution {
public:
	typedef vector<int>::size_type sz_t;

public:
	/**
	 * 经典的最大子序列和问题
	 */
	int maxSubArray(vector<int>& nums) {
		sz_t nSize = nums.size();
		if (nSize <= 0)
			return 0;

		int maxSum = nums[0], validSum = nums[0];
		for (sz_t i = 1; i < nSize; ++i) {
			if (validSum <= 0)
				validSum = nums[i];
			else
				validSum += nums[i];

			maxSum = std::max(maxSum, validSum);
		}

		return maxSum;
	}
};
```
我果真不适合写题解，写文章啊！
文末推荐github上的一份题解：[Maximum Subarray - 暴力解，前缀和解，分支解和动态规划解](https://github.com/azl397985856/leetcode/blob/master/problems/53.maximum-sum-subarray-cn.md)
尤其是其中的题解四使用的是题目要求的分治法