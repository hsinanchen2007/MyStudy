### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        maxx1 = max(rec1[0],rec2[0])
        maxy1 = max(rec1[1],rec2[1])
        minx2 = min(rec1[2],rec2[2])
        miny2 = min(rec1[3],rec2[3])
        w = max(0,minx2-maxx1)
        h = max(0,miny2-maxy1)
        area = w * h
        return area != 0
```