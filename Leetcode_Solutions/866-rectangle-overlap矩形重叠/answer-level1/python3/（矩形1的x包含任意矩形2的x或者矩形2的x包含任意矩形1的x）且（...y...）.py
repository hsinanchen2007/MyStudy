### 解题思路
同理，对于求相交面积的题目，只需要判断重叠后，对四个x排序，同理y，最后取(x数组[2]-[1])*(y数组[2]-[1])即是重叠面积

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1,y1,x2,y2=rec1
        x3,y3,x4,y4=rec2
        return (x1<x3<x2 or x1<x4<x2 or x3<x1<x4 or x3<x2<x4)and(y1<y3<y2 or y1<y4<y2 or y3<y1<y4 or y3<y2<y4)
```