### 解题思路
定义diff = a[n]-a[n-1], 相邻两天的股价差， 其中a[i]表示第i天的股价
定义f(n) 为第n天卖出，可以达到的最大收益（前提是第{1,2,3,...,n-1}的某一天进行了购买）

利用穷举的思想，将f(n) f(n-1) 写出来
f(n) = max(a[n]-a[1], a[n]-a[2], a[n]-a[3], ... ,a[n]-a[n-1])
f(n-1) = max(a[n-1]-a[1], a[n-1]-a[2], a[n-1]-a[3], ... ,a[n-1]-a[n-2])

f(n) = max(a[n]-a[1], a[n]-a[2], a[n]-a[3], ... ,a[n]-a[n-1])
     = max(a[n-1]+diff -a[1], a[n-1]+diff-a[2], a[n-1]+diff-a[3], ... ,diff)
     = max(max(a[n-1]+diff -a[1], a[n-1]+diff-a[2], a[n-1]+diff-a[3], ... ,diff), diff)
     = max(max(a[n-1]-a[1], a[n-1]-a[2], a[n-1]-a[3], ..., a[n-1]-a[n-2])+diff, diff)
     = max(f(n-1)+diff, diff)

至此状态转移方程出来了
f(n) = max(f(n-1)+diff, diff), 其中diff = a[n]-a[n-1] 

需设置一个岗哨，求解动态规划矩阵的过程中，一直监视当前最大值
程序执行完成，哨岗中的值就是问题答案。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        rst = 0
        if len(prices)>1:
            dpi = 0
            for i in range(1, len(prices)):
                priceDiff = prices[i] - prices[i-1]
                dpi = max(dpi+priceDiff, priceDiff)
                rst = dpi if dpi > rst else rst
        return rst

    # 方法2： 参考labuladong所说的状态机框架，题目123的的高赞讲解
    # def maxProfit(self, prices: List[int]) -> int:
    #     count = len(prices)
    #     if count <= 1:
    #         return 0
    #     dp = [[0]*count, [0]*count]
    #     for i in range(count):
    #         if i == 0:
    #             dp[0][0] = 0
    #             dp[1][0] = -prices[0]
    #             continue
    #         dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i])
    #         dp[1][i] = max(dp[1][i-1], -prices[i])
    #     return dp[0][-1]
            

```