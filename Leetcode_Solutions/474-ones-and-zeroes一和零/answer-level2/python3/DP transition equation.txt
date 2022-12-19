As others already pointed out, this is a knapsack problem. We have constrained capacity ($m$ zeros and $n$ ones) but we want to take as much items as possible. The problem can be solved using dynamic programming: suppose we have an optimal bag of items. If we remove any item from the bag, the remaining items must be optimal under the reduced capacity. 

Let $f(i, j, k)$ be the value function (the maximal number of items we can get) when we restrict to previous $k$ items `strs[:k+1]` with capacity $i$ zeros and $j$ ones. For item $k$, we have two choices: either take it or not take it. We should choose the option that yields highest value:

$f(i, j, k) = \max\left\{ f(i, j, k-1),\,\, 1 + f(i-k_0, j-k_1, k-1)\right\}$,

where $k_0$ is the number of zeros in `strs[k]`, and $k_1$ is the number of ones in `strs[k]`.

Python code below. The program has TLE.

```
import numpy as np

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        f = np.zeros(shape=(m+1, n+1), dtype=int)
        
        for k in range(len(strs)):
            k0 = strs[k].count('0')
            k1 = strs[k].count('1')
            for i in range(m, k0 - 1, -1):
                for j in range(n, k1 - 1, -1):
                    f[i, j] = max(f[i, j], f[i - k0, j - k1] + 1)
        return f[m, n]
```

Note from the equation above that in implementation we don't have to maintain the third variable $k$. We can optimize $f(i, j)$ over and over. In fact the specific order of the elements in `strs` does not matter. 