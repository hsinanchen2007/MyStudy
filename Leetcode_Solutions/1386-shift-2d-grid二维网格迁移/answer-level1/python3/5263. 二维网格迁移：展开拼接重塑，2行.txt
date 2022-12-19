![image.png](https://pic.leetcode-cn.com/c3cedafcab27d159f3eea405c8a5583bc9482d62632d2ef040c2d5d6426ca610-image.png)


用`itertools.chain`展开二维数组，然后错位拼接获得新数组，最后用`numpy.reshape`重塑数组即可，304ms仅供参考。

```python []
import numpy as np
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n, a = len(grid), len(grid[0]), [*itertools.chain(*grid)]
        return np.array(a[-k % (m * n): ] + a[: -k % (m * n)]).reshape(m, n)
```
