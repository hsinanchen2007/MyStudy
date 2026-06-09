### 解题思路
斐波那契数列

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        l = [0, 1]
        while N >= len(l):
            l.append(l[len(l) - 2] + l[len(l) - 1])
        return l[N]
```