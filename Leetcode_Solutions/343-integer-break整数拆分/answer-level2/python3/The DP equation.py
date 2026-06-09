
Let $f(n)$ be the maximal product of decompositions of $n$. The Bellman equation is a little bit tricky:

$f(n) = \max\left\{ \max_{1\leq j<n}\left\{j\cdot f(n-j)\right\},\quad j\cdot(n - j)\right\}$.


Python code
```
class Solution:
    def integerBreak(self, n: int) -> int:
        f = [1 for _ in range(n + 1)]
        for m in range(2, n + 1):
            for j in range(1, m):
                f[m] = max(f[m], j * f[m - j], j * (m - j))
        return f[n]

```
