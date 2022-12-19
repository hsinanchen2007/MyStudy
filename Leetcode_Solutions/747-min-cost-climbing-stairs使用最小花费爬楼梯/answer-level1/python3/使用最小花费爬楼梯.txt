### 解题思路
想到的是动态规划，原来是每个累计计算呢，时间o(n)，空间o(n)；这里的空间可以优化，只用两个数存储f[i-2]和f[i-1]即可，空间优化为o(1)


### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        f = []
        xiabiao = len(cost) -1
        f.append(cost[0])
        f.append(cost[1])
        for i in range(2,len(cost)):
            f.append(min(f[i-2]+cost[i],f[i-1]+cost[i]))
        return f[xiabiao]
```