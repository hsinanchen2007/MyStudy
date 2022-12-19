
### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        if n <= 0:
            return 1
        a = 1
        b = 0
        while n > 0:
            x = n % 10
            n //= 10
            a *= x
            b += x
        return a-b
```