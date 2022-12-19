转载自[https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation]()

递归解决方案非常慢，因为它的运行时间是指数级别

原始问题等同于：

找出需要为正的num的子集和负的num的子集，且两个子集的阶之和为nums.size，以使总和等于目标

我们设P为正子集而N为负子集

例如：

给定nums = [1、2、3、4、5]和target= 3，那么一个可能的解决方案是+1 -2 +3 -4 +5 = 3

在这里，正子集为P = [1、3、5]，负子集为N = [2、4]


然后，让我们看看如何将其转换为Subset问题：

 
```                 
sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2 * sum(P) = target + sum(nums)
```       

因此，原始问题已转换为子集和问题，如下所示：

找出num的子集P，使sum(P)=(target + sum(nums)/ 2


请注意，以上公式已证明 target + sum(nums)必须为偶数，因此我们可以利用这一事实来快速识别没有解决方案的输入

有关如何解决子集和问题的详细说明，请参阅参考[https://leetcode-cn.com/problems/partition-equal-subset-sum/]()

附上c++代码：
```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};
```

