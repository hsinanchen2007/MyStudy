```python
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        num = []
        while n // 10 != 0:
            i = n % 10
            num.append(i)
            n = n // 10

        num.append(n)
        p = 1
        s = 0
        for item in num:
            p = p * item
            s = s + item
        return p - s
```