### 解题思路
此题的思路与 435题 一样
区别在于这里边界也算重叠区域，即 [1,2]和[2,3]为重叠区间

### 代码

```python
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points)==0:
            return 0
        points.sort(key=lambda x:x[1])
        cnt=1
        end=points[0][1]
        for i in range(1,len(points)):
            if points[i][0]<=end:
                continue
            cnt+=1
            end=points[i][1]
        return cnt
```