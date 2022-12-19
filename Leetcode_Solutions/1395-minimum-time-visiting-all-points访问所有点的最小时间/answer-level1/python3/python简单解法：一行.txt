### 解题思路
每两点最短距离就是max(abs(y2-y1),abs(x2-x1))

### 代码

```python
class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        c=0
        for i in range(len(points)-1):
            c+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]))
        return c
```
一行的话就是
```
return sum(max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1])) for i in range(len(points)-1))
```
