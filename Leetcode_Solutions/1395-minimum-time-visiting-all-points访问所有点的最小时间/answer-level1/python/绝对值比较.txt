### 解题思路
所用的距离（时间）其实由两坐标点之间横纵差值最大的一项决定，如(1,1)到(3,4),abs(3 - 1) < abs(4 - 1),所以距离为abs(4 - 1)，
通过比较每一个点与前一个点之间最大的横纵距离并相加即可。

### 代码

```python
class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        self.points = points
        count = 0
        for i in range (0, len(points) - 1):
            if(abs(points[i + 1][0] - points[i][0]) >= abs(points[i + 1][1] - points[i][1])):
                count += abs(points[i + 1][0] - points[i][0])
            else:
                count += abs(points[i + 1][1] - points[i][1])
        return count
```