### 解题思路
爬到当前台阶（i）的最小消耗只与前第一台阶（i-1）和前第二台阶(i-2)的最低消耗有关，因为每个台阶只能爬一个或者两个。
那个状态转移方程很容易就出来了：**dp[i] = min(dp[i - 1], dp[i - 2]) + cost(i)**
优化：因为每次爬只会和i-1、i-2两个台阶有关系，与i-3等的台阶没有关系，所以可以把dp数组优化成只有两个值的，只需要**mod2**就可以实现改优化。


#### 优化前
```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        size = len(cost)
        if size <= 2:
            cost.append(0)
            return min(cost)
        cost.append(0)
        dp = [0 for _ in range(size + 1)]
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2, size + 1):
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]

        return dp[-1]
```
时间复杂度：O(N)
空间复杂度：O(N)

#### 优化后：使用滚动数组
```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        size = len(cost)
        if size <= 2:
            cost.append(0)
            return min(cost)
        cost.append(0)
        dp = [0 for _ in range(2)]
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2, size + 1):
            dp[i % 2] = min(dp[(i - 2) % 2], dp[(i - 1) % 2]) + cost[i]

        return dp[size % 2]
```
时间复杂度：O(N)
空间复杂度：O(1)

