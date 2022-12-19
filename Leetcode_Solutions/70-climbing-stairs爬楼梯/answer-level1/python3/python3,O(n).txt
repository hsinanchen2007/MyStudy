### 解题思路
递归超时，采用循环的方式
简单的动态规划问题
f(1) = 1, f(2) = 2, f(n) = f(n-1) + f(n-2)
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2: return n
        a = 1; b = 2
        for i in range(3, n+1):
            tmp = a + b
            a = b; b = tmp
        return b
```