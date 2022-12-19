### 解题思路
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        num = {}
        num[0] = 0
        num[1] = 1
        if n > 1:
            for i in range(2,n+1):
                num[i] = num[i-2] + num[i-1]
        return int(num[n]%(1000000007))
```