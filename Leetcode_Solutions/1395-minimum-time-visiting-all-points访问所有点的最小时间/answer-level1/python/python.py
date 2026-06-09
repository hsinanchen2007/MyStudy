### 解题思路
先得到列表长度，再比较列表里x,y坐标点前后项差值哪个最大，取最大的那个就是最优时间。

### 代码

```python
class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        minTime=0
        num=len(points)
        for i in range(0,num-1):
            xm=abs(points[i+1][0]-points[i][0])
            ym=abs(points[i+1][1]-points[i][1])
            if xm == ym :
                minTime+=xm
            if xm < ym :
                minTime+=ym
            if ym < xm :
                minTime+=xm
        return minTime
```