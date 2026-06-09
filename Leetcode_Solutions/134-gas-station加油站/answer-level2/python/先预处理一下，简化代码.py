### 解题思路
先直接用 $gas-cost$ 得到一个差值数组。在这个数组中为负的项不可能做为出发点。对于连续出现的正值，我们只需要检查第一个，检查时从当前值一直往后累加，只要不为负就成功了。

### 代码

```python3
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        N = len(gas)
        rem = [gas[i]-cost[i] for i in range(N)]
        i = 0
        while i < N :
            while i<N and rem[i] < 0 : i += 1 # 找到第一个正值
            temp = 0
            for j in range(N) :
                temp += rem[(i+j)%N]
                if temp < 0 : break
            if temp >=0 : return i
            while i<N and rem[i] >= 0 : i += 1 # 跳过连续的正值
        return -1
```