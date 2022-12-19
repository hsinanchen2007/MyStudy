### 解题思路
这里没有采用dp来记录每次的可能性，而是直接采用卷积的定义，简化代码的写法
(a * h)[n] = \sum_{k=-\infty} ^ {\infty} a[k] h[n-k]
### 代码

```python3
import numpy as np
class Solution:
    def twoSum(self, n: int) -> List[float]:
        one_dice = np.array([1/6 for _ in range(6)])
        res = np.array([1/6 for _ in range(6)])
        for i in range(1, n):  # repeat n-1 time
            res = np.convolve(res, one_dice)
        return res
```