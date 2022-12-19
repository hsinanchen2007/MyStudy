暴力解题

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        if num<10:
            return num
        return self.addDigits(sum([int(i) for i in str(num)]))
```