### 解题思路

f(n)表示当前是最小花费的第n个阶梯，要到达第n层可以从n-1层或者n-2层到达，假设：
1、从n-1层到n层，则f(n) = f(n-1) + v(n-1)
2、从n-2层到n层，则f(n) = f(n-2) + v(n-2)

所以，到达n+1阶台阶的最小花费为：f(n) = min(v(n-2) + f(n-2), f(n-1) + v(n-1))

初始状态f(1) = f(2) = 0

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost += [0]
        cur, pre, pre_pre = 0, 0, 0
        
        for i in range(2, len(cost)):
            pre_pre = pre
            pre = cur
            cur = min(pre + cost[i-1], pre_pre + cost[i-2])
            
        return cur
```