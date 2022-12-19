```
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        left = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0])
        right = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1])
        return left > 0 and right > 0
```