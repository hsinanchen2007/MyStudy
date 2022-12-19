很普通的解法，献丑了。
```python
class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        x0, y0 = coordinates.pop(0)
        x1, y1 = coordinates.pop(0)
        if x1==x0:
            return False
        k = (y1 - y0)/(x1 - x0)
        while coordinates:
            x0, y0 = x1, y1
            x1, y1 = coordinates.pop(0)
            if x1 ==x0 or (y1 - y0)/(x1 - x0) != k:
                return False
        return True
```