### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        a = 0; b = 1
        for i in range(2, N + 1):
            c = a + b
            a = b
            b = c
        return b
```