## 思路:

思路一：自顶向下（DP）

```python
from functools import lru_cache
class Solution:
    @lru_cache
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        if n % 2 == 0:
            return self.integerReplacement(n // 2) + 1
        else:
            return min(self.integerReplacement(n + 1), self.integerReplacement(n - 1)) + 1
```

思路二：找规律

偶数当然  `n / 2` 最好

奇数 当 `n != 3` 并且 `n + 1`能被整除时， `+1`最好

```python
class Solution:
    def integerReplacement(self, n: int) -> int:
        step = 0
        while n > 1:
            if n & 1 == 0: n >>= 1
            elif (n + 1) % 4 == 0 and n != 3: n += 1
            else:
                n -= 1
            step += 1
        return step
```

