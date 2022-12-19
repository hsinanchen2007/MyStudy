### 解题思路
被最后的模运算坑了一波，原因是模运算前后两者都应该是整数类型。

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1
        if n == 0: return a
        if n == 1: return b
        for i in range(n-1):
            a = a + b
            a, b = b, a
        return int(b % int(1e9+7))
```