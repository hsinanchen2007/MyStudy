### 解题思路
两点之间的间距，取最大的那个，作为时长，遍历即可。

### 代码

```python3
import math

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        for i in range(len(points)):
            if i < (len(points)-1):
                a = abs(points[i+1][0]-points[i][0])
                b = abs(points[i+1][1]-points[i][1])
                c = max(a, b)
                res = res + c
            else:
                pass
        return res

```