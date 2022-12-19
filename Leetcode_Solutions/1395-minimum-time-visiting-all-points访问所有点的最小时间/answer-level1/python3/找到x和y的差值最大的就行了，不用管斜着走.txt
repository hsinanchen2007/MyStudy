### 解题思路
走多了有一个轴没对齐先不管，另外差值大的先对齐了

### 代码

```python3
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        for i in range(len(points) - 1):
            res = res + max(abs(points[i][0] - points[i + 1][0]),abs(points[i][1] - points[i + 1][1]))
        return res
```