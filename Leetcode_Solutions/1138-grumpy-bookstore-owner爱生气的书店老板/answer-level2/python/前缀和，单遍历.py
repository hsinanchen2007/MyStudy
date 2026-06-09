### 解题思路
一边加一边计算，最后算多一次calm=max(calm,p[-1]-p[-1-X])，是因为len(p)=len(customers)+1.

### 代码

```python3
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        total=0
        p=[0]
        calm=0
        for i in range(len(customers)):
            p.append(p[-1]+customers[i]*grumpy[i])
            total+=customers[i]*(1-grumpy[i])
            if i>=X:
                calm=max(calm,p[i]-p[i-X])
        calm=max(calm,p[-1]-p[-1-X])
        return total+calm
        
```