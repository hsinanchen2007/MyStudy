### 解题思路
很巧妙地利用投影，把二维的重叠问题转化为一维的区间判断问题
然后重叠的场景判断条件复杂，可以判断不重叠的情况，把重叠的情况写到else里面
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1 = rec1[0]
        y1 = rec1[1]
        x2 = rec1[2]
        y2 = rec1[3]
        
        xrange1 = rec2[0]
        yrange1 = rec2[1]
        xrange2 = rec2[2]
        yrange2 = rec2[3]
        
        if xrange1 >= x2 or x1 >= xrange2 or y1 >= yrange2 or yrange1 >= y2:
            return False
        
        else: 
            return True
        
```