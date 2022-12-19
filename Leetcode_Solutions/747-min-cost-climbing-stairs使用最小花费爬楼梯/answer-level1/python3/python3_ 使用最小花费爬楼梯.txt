```python
def minCostClimbingStairs(cost):
    """
        1. dp问题: dp[i] = min(dp[i] + dp[i - 1], dp[i] + dp[i - 2])
    """
    for i in range(2, len(cost)):
        cost[i] += min(cost[i - 1], cost[i - 2])
    return min(cost[-1], cost[-2])

print(minCostClimbingStairs([10,15,20]))
print(minCostClimbingStairs([10,15]))
print(minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))
```