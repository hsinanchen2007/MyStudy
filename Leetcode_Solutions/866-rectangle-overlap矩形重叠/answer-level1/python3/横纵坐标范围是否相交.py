### 解题思路
两个矩形A，B相交意味这这二者的横坐标范围A(x1，x2）和B(x1'，x2'）存在交集，而纵坐标范围(y1,y2),(y1',y2')也同样存在交集
只需要考虑不相交的情况，那就是这两个矩形的横坐标范围没有交集或者纵坐标范围也没有交集
也就是x2<=x1'or x1>=x2' or y2<=y1' or y1>=y2'


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[2]<=rec2[0] or rec1[0]>=rec2[2] or rec1[1]>=rec2[3] or rec1[3]<=rec2[1]:
            return False
        else:
            return True
```