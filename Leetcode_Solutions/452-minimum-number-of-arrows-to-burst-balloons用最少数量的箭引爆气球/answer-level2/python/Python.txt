### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(points)==0:
            return 0
        def takesecond(a):
            return a[1]

        points.sort(key=takesecond)
        end=points[0][1]
        ans=1
        for i in points:
            if i[0]<=end:
                continue
            else:
                end=i[1]
                ans=ans+1
        return ans

```