### 解题思路
代码有点丑
1   0
2   max(A1, A2)
3   max(A1+A3, A2)
4   max(A1+A3, A2+A4, A2+A3)
5   max(A1+A3+A4, A1+A3+A5, A2+A3+A5, A2+A4)
6   max(A1+A3+A5, A1+A3+A4+A6, A2+A4+A6, A2+A4+A5, A2+A3+A5) 
f(n) = max(f(n-2)+A(n-1), f(n-1)+A(n))
因为求最小值而且每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999] 大于等于0
如 A2+A4 肯定等于 min（A2+A4，A2+A4+A5, A2+A4+A6）
### 代码
```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        length = len(cost)
        res = {}
        if length == 0:
            return 0
        if length == 1:
            return 0
        res[1] = 0
        if length == 2:
            return min(cost[0], cost[1])
        res[2] = min(cost[0], cost[1])
        if length > 2:
            for i in range(3, length + 1):
                res[i] = min(res[i-2]+cost[i-2], res[i-1]+cost[i-1])
        return res[length]
        
```