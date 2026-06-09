借助numpy进行向量化计算.
思路和大部分答案一样, 只是使用numpy进行了向量化运算(本质上是批量化)

```
import numpy as np
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return np.max(np.abs(np.diff(points, axis=0)), axis=1).sum()
```
