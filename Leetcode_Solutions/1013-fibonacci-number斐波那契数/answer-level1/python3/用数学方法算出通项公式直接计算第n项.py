```
class Solution:
    def fib(self, N: int) -> int:
        a = (1+5**0.5)/2
        b = (1-5**0.5)/2
        return int((a**N-b**N)/5**0.5)
```
