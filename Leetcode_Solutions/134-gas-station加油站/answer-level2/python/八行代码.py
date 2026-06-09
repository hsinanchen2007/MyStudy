### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas)<sum(cost):return -1
        num,index = 0,0
        for i in range(len(gas)):
            num+=(gas[i]-cost[i])
            if num<0:
                num=0
                index= i+1
        return index
```