### 解题思路
动态规划：首先，我们用最笨的办法，将原数组元素个数为1、2、3的情况作为特殊情况列出来。这样比较清晰（牺牲了代码的简洁性）。但是这样的情况，我们可以清晰的分析在后面更多元素加上的时候出现分支的情况。
1、关键条件：第一个元素和最后一个元素不能同时出现在最大值的累加结果中。
2、所以我们可以考虑，在原有状态转移方程的基础上，分别对包含首元素、去除尾元素和包含尾元素、去除首元素这两种情况分别求解。
第一种情况我们只需要输出Dp数组的倒数第二项即可，然后保存；第二种情况我们只需要在初始化数组元素的时候，从Dp[1]开始初始化，并且忽略Dp[0]，然后套用状态转移方程一直计算到最后一项。输出最后一项，保存；
3、最后输出的结果就是保存的两种情况输出的其中最大值


### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
		if ((int)nums.size() == 1) return nums[0];
		if ((int)nums.size() == 2) return max(nums[0], nums[1]);
        if ((int)nums.size() == 3) return max(nums[0], max(nums[1],nums[2]));
        vector<int> dp((int)nums.size());
		//含有第一个元素、不含有最后一个元素的情况下，最大值
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < (int)nums.size()-1; ++i)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
        int maxSum[2]={0,0};
        maxSum[0]=dp[(int)nums.size()-2];
		//含有最后一个元素、不含有第一个元素的情况下，最大值
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < (int)nums.size(); ++i)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
        maxSum[1]=dp[(int)nums.size()-1];
		//两个最大值取Max即可
		return max(maxSum[0],maxSum[1]);

    }
};
```