```
def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1 = max(rec1[0],rec2[0])
        y1 = max(rec1[1],rec2[1])
        x2 = min(rec1[2],rec2[2])
        y2 = min(rec1[3],rec2[3])
        w = max(0,x2-x1)
        h = max(0,y2-y1)
        aera = w*h
        return aera != 0
```
