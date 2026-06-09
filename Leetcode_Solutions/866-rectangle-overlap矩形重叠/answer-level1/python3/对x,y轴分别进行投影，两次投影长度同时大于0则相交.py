```
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1,y1,x2,y2=rec1
        x3,y3,x4,y4=rec2
        if x1<x4<=x2 or x1<=x3<x2 or (x1<=x3<=x2 and x1<=x4<=x2) or (x3<=x2<=x4 and x3<=x1<=x4):
            if y1<=y3<y2 or y1<y4<=y2 or (y1<=y3<=y2 and y1<=y4<=y2) or (y3<=y1<=y4 and y3<=y2<=y4):
                return True
        return False
```
