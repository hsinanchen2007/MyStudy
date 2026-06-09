解题思路：因为求全局最优解，考虑动态规划
一、最优子结构
1. 假设f(1)~f(n-1)已知，如何计算f(n)？
因为不能选相邻的数，因此存在选n或不选n的情况，
如果选了n，就不能选n-1，那么f(n) = f(n-2) + nums[n-1]
如果不选，则f(n) = f(n-1)
因此f(n)依赖于先前的有限个值
存在最优子结构
二、重叠子问题
1. 根据递推方程，显然存在重叠情况
![1.png](https://pic.leetcode-cn.com/abfbaa137aee5e3635be6560bc43f1b6b148b867981799296d70089dcd274378-1.png)

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 特殊情况判断
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        
        dp = [0] * len(nums)  # 定义dp:一维列表,dp[i]表示从0~i的最大的总和
        # 初始化dp
        dp[0] = nums[0]
        dp[1] = max(nums[0:2])

        # 自底向上填表
        for i in range(2, len(nums)):  # 从2到尾
            dp[i] = max(dp[i-2] + nums[i], dp[i-1])  # 递推方程
        
        return dp[-1]  # 返回最后一个值
```