```
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        x1, y1 = toBeRemoved
        ret = []
        for item in intervals:
            x, y = item
            if x >= x1 and y <= y1:
                continue            
            if x < x1 and y > y1:
                ret.append([x, x1])
                ret.append([y1, y])
            else: 
                if x >= x1 and x <= y1:
                    x = y1
                if y >= x1 and y <= y1:
                    y = x1 
                ret.append([x, y])
        return ret
```
