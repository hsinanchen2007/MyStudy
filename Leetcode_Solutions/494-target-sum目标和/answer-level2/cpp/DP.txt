### 解题思路
将问题的解看成为状态的答案，并分析不同状态答案的关系，以第一次转移状态过程为例：问题要求我们求出0，到nums.size()-1和为S的个数，而该问题可分为求从1到nums.size()-1和为S-nums[0]的解个数与从1到nums.size()-1和为S+nums[0]的解个数，注意一个可以优化的细节，当目标值绝对值大于从该下角标curr开始到nums.size()-1的部分和时,是不可能有解的，因为超出了curr后面那部分所能表示的上下界。

### 代码

```cpp
class Solution {
public:
int methods(map<int, map<int, int>>&dp, int*sumOfPost, int curr,vector<int>&nums,int target)
{
	if (curr == nums.size() - 1)
	{
		if (nums[curr] == target || nums[curr] == -target)
		{
			dp[curr][target] = 0;
            if(nums[curr] == target)
            dp[curr][target]++;
            if(nums[curr] == -target)
            dp[curr][target]++;
			return dp[curr][target];
		}
		else {
			dp[curr][target] = 0;
			return 0;
		}
	}
	if(dp.count(curr)!=0)
		if (dp[curr].count(target) != 0)
		{
			return dp[curr][target];
		}
	if (target > sumOfPost[curr] || target < -sumOfPost[curr])
	{
		dp[curr][target] = -1;
		return -1;
	}
	int re = 0;
	int t = 0;
	t = methods(dp, sumOfPost, curr + 1, nums, target - nums[curr]);
	if (t != -1)
		re += t;
	t = methods(dp, sumOfPost, curr + 1, nums, target + nums[curr]);
	if (t != -1)
		re += t;
	dp[curr][target] = re;
	return re;
}
    int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.size()==1)
    {
        if(nums[0]==S||nums[0]==-S)
        return 1;
        else return 0;
    }
    int size = nums.size();
	int*sumOfPost = new int[size];
	sumOfPost[size - 1] = nums[size - 1];
	for (int i = size - 2; i >= 0; i--)
		sumOfPost[i] = nums[i] + sumOfPost[i + 1];
	map<int, map<int, int>>dp;
	int re= methods(dp, sumOfPost, 0, nums, S);
    if(re<0)
    return 0;
    else return re;
    }
};
```