都说什么动态规划，吓到我了，结果发现其实就是最朴素的想法...

两种解法，前一种稍微快点，但也基本大同小异。

```python3
class Solution:
    def fib(self, n: int) -> int:
        a = {}
        a[0] = 0
        a[1] = 1
        for i in range(2, n+1):
            a[i] = a[i-1] + a[i-2]
        return a[n] % 1000000007
```

```python3
class Solution:
    def fib(self, n: int) -> int:
        a = [0, 1]
        for i in range(n):
            a[0] = a[0] + a[1]
            t = a[1]
            a[1] = a[0]
            a[0] = t
        return a[0] % 1000000007
```