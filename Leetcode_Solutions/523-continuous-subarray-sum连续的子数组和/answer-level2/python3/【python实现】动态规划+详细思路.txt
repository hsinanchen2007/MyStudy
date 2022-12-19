解题思路：
一、最优子结构
1. 假设已经知道`dp[0] ~ dp[n-2]`，求dp[n-1]
则dp[i]表示0~i的总和，
那么dp[i] = dp[i-1] + nums[i]
则(i, j)之间的和`sum`可以表示为：`dp[j] - dp[i] + nums[i]`
只要满足条件，就立刻返回

二、重叠子问题
1. 根据递推方程，易得存在重叠子问题

三、时间复杂度
双重循环，为`O(n^2)`

![1.png](https://pic.leetcode-cn.com/83690c170b30d5f8271ee099cd3ade4304fc5878d9c780ad92fccc03df394ee7-1.png)


```
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
		# 特殊情况判断
        if len(nums) <= 1:
            return False
        n = len(nums)
        dp = [0] * n  # 定义dp
        # 自底向上
        for i in range(1,n):
            dp[i] = dp[i-1] + nums[i]
        # 遍历总和
        for i in range(n-1):
            for j in range(i+1, n):
                sums = dp[j] - dp[i] + nums[i]  # 区间差
                # 判断是否满足条件
                if k == 0:  # 考虑极端条件
                    if sums == 0:  # 满足条件就返回
                        return True
                else:
                    if sums % k == 0:  # 满足条件就返回
                        return True
        return False
        
```