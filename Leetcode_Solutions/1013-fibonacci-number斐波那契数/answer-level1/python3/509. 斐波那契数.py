### 解题思路
递归求解。

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if not N: 
            return 0
        elif N == 1:
            return 1
        else: 
            return self.fib(N-1) + self.fib(N-2)
```