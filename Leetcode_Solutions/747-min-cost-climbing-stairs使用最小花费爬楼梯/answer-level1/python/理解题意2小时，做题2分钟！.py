### 解题思路
感谢金艾一发布的【吃屎问题，做题2分钟，理解题意俩小时】。我看官方题解看了两小时没看明白，最后看这个题解，秒懂了。
这道题和#198 #98不一样的地方在于，当前状态不仅与上一状态有关，还与上上个状态有关。
即对于当前台阶f(i)来说，不能单纯的等于dp0 = cost(i) + f(i-1), dp1 = f(i-1)
而且其最大值在最后一个台阶的下一个，如[10, 15, 20]。
cost = [1, ×100, 1, ×1, 1, ×100, 1, 1, ×100, 1]，其中没经过的打×，跳过数分别为22212
cost = [dp0,dp1]
如果cost[2]被选中，则cost[0]和cost[1]都可能被选中，选择小的那个即可：min(dp0, dp1) + cost[2]=1+1=2=新的dp1
如果cost[2]不被选中，则cost[1]一定会被选中，因为最多跨两个台阶：旧的dp1=100=新的dp0

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) == 0: return 0
        if len(cost) == 1: return cost[0]

        dp0, dp1 = cost[0], cost[1]
        for c in cost[2:]:
            dp1, dp0 = min(dp0, dp1)+c, dp1
        return min(dp1, dp0)
```