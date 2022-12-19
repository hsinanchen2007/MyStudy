### 代码

```python3
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        result = 0
        start = float('-inf')
        for i in range(len(points)):
            if start < points[i][0]:
                result += 1
                start = points[i][1]
        return result

```