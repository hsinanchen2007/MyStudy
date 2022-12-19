### 解题思路
此处撰写解题思路
用list储存，效率不是很高
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        dp=[1,1]
        for i in range(n-1):
            dp.append(dp[-1]+dp[-2])
        return dp[-1]
```