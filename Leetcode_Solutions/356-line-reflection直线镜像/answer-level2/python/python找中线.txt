```python []
class Solution(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        if len(points) == 0:
            return True
        
        min_x = max_x = None
        lut = {}
        for x, y in points:
            min_x = min(min_x, x) if min_x is not None else x
            max_x = max(max_x, x) if max_x is not None else x
            if (x,y) not in lut:
                lut[(x,y)] = True

        middle = 1.0 * (min_x + max_x) / 2
        for x, y in lut:
            x1, y1 = 2*middle-x, y
            if (x1, y1) not in lut:
                return False
        return True

```
