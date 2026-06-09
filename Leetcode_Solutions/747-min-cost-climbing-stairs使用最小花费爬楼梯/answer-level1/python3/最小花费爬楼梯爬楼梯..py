### 动态规划
- bsic base: pre = cost[0], cur = cost[1]
- 状态转移: 可以看到 对于第 i 个楼梯, 要计算踩到它, 可能是从两种状态之一转移来的, 一是 i-2, 另一是 i-1, 故 cur = min(asum(i-2)+cost[i], asum(i-1)+cost[i])
- 最后返回 min(pre, cur) 是由于最开始即可以从 0, 也可以从 1 开始

### 代码

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        pre = cost[0]
        cur = cost[1]
        for i in range(2, len(cost)):
            temp = cur
            cur = min(pre+cost[i], cur+cost[i])
            pre = temp
        return min(cur, pre)
```