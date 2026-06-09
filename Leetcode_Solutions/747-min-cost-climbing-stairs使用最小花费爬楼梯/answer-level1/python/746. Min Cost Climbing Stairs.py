跟爬楼梯问题相似
公式: fx = fx + min(fx-1, fx-2)

```
# 44 ms, 在所有 Python 提交中击败了97.99%的用户
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        if not cost: return 0
        if len(cost) < 2: return min(cost)
        for i in range(2, len(cost)):
            # cost[i] += min(cost[i - 1], cost[i - 2])
            cost[i] += cost[i - 2] if cost[i - 1] > cost[i - 2]: else cost[i - 1]
        # return min(cost[-1], cost[-2])
        return cost[-1] if cost[-1] < cost[-2] else cost[-2]
```
