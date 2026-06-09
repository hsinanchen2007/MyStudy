### 解题思路
从1开始遍历直至n2>x,直接输出n-1即可，
### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        n=1
        while n*n<=x:
            n=n+1
        else:
            return n-1
```