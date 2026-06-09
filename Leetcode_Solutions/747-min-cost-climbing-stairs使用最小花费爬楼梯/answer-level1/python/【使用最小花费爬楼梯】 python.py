官方解答看的我有点迷糊，分享以下我的思路：
设站到第n个台阶时的体力花费为c(n)，要么从n-1级台阶爬上来花费c(n-1)+cost[n]，要么从n-2级台阶爬上来花费c(n-2)+cost[n]
那么c(n) = min(c(n-1)+cost[n],c(n-2)+cost[n])
最后一步到楼顶时要么花费c(n)要么花费c(n-1)
python解法↓
```
class Solution(object):
    def minCostClimbingStairs(self, cost):
        # c(n) = min(c(n-1)+cost[n],c(n-2)+cost[n])
        if len(cost)==0 or len(cost)==1:
            return 0
        c_0 = 0
        c_1 = cost[0]
        for i in range(1,len(cost)):
            c_n = min(c_0,c_1) + cost[i]
            c_0, c_1 = c_1, c_n
        return min(c_0, c_1)
```
