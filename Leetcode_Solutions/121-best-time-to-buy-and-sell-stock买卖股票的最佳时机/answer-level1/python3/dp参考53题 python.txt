### 解题思路
在集中刷动态规划参考了这道
53.最大子序和 第6个题解
[https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-jie-fa-4xing-pythondai-ma-by-mcdu/]()


用dp数组描述到达第i天时的最大收益
subsidy为相邻两天的收益 = i天价格 - （i-1）天价格

第i天的最大收益= max(第i-1天的最大收益 +subsidy ,subsidy)
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        size = prices.__len__()

        if size < 2:
            return 0

        dp = prices[:]

        dp[0] = 0
        for i in range(1, size):
            subsidy = prices[i] - prices[i - 1]
            dp[i] = max(dp[i - 1] + subsidy, subsidy)

        return max(max(dp), 0)

```