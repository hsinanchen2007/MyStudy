### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<3:return n
        dp_0,dp_1 = 1,2
        for i in range(2,n):
            dp_0,dp_1 = dp_1,dp_0+dp_1
        return dp_1
```