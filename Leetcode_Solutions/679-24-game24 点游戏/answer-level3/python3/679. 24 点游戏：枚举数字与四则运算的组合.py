
```python []
class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        opt = (lambda i, j: i + j, lambda i, j: i - j, lambda i, j: i * j, lambda i, j: not j and 2000 or i / j)
        f = lambda a, b, c, d: any(
            abs(x(y(z(a, b), c), d) - 24) < 0.0001 \
            or abs(x(a, y(b, z(c, d))) - 24) < 0.0001 \
            or abs(x(y(a, b), z(c, d)) - 24) < 0.0001
            for x, y, z in itertools.product(opt, repeat=3)
        )
        return any(f(*abcd) for abcd in itertools.permutations(nums))
```