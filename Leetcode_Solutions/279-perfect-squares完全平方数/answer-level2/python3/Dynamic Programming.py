Let $f(n)$ be the function we are trying to compute. The dynamic programming relation is

$f(n) = 1 + \min_{1\leq i\leq\sqrt{n}}\left\{ f(n-i^2) \right\}$.

Namely, we can decompose $n$ as $n = i^2 + (n - i^2)$ for some $1\leq i\leq\sqrt{n}$. Any such $i$ will increase the count by one, and we just need to select the $i$ for which $f$ has the smallest value on the remaining part $(n-i^2)$.

The Python code is below

```
import math

class Solution:
    def numSquares(self, n: int) -> int:
        f = [0, 1]
        for m in range(2, n+1):
            f.append(1 + min([f[m - i**2] for i in range(1, math.floor(math.sqrt(m))+1)]))
        return f[n]
```

However, note that this solution will yield timout error. The official may consider fixing the problem. 
