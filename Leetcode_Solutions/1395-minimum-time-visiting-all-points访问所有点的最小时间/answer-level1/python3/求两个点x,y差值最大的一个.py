### 解题思路
1. 两个点横纵坐标分别相减，取最大的即为当前移动最小时间。

### 代码
```
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        accummulate = 0
        index = 1
        while index <len(points):
            accummulate += max(abs(points[index][0]-points[index-1][0]), abs(points[index][1]-points[index-1][1]))
            index += 1
        return accummulate
```