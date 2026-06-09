抛砖引玉，提供一个快速幂的思路，由于维度太大，时间复杂度太高

**不建议用，会超时的**

```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        import numpy as np
        arrLen = min(steps // 2 + 1, arrLen)
        arr = [[0] * arrLen for _ in range(arrLen)]
        for i in range(arrLen):
            arr[i][i] = 1
            if i > 0:
                arr[i - 1][i] = 1
                arr[i][i - 1] = 1
            if i < arrLen - 1:
                arr[i + 1][i] = 1
                arr[i][i + 1] = 1
        c = np.mat(arr, dtype=np.dtype('O'))
        c = c ** (steps)
        return c.A1[0] % (10**9+7)
```
