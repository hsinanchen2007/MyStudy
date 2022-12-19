### 解题思路
解题思路就是没有思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        res = [0 for _ in range(n+1)]
        res[1] = 1
        for i in range(2, n+1):
            res[i] = res[i-1] + res[i-2]
        return res[n] % 1000000007
```