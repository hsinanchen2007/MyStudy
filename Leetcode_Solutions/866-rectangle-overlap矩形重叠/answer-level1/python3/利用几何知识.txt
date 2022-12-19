### 解题思路
几何题。
两个矩形没有交集的情况是两个矩形的长宽加起来小于这两个矩形的能形成的最大矩形的长和宽。


### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        def get_range(rect):
            return (rect[2] - rect[0], rect[3] - rect[1])
        
        x1, y1 = get_range(rec1)
        x2, y2 = get_range(rec2)

        new_x = max([rec1[0], rec1[2], rec2[0], rec2[2]]) - min([rec1[0], rec1[2], rec2[0], rec2[2]])
        new_y = max([rec1[1], rec1[3], rec2[1], rec2[3]]) - min([rec1[1], rec1[3], rec2[1], rec2[3]])

        if new_x < x1 + x2 and new_y < y1 + y2:
            return True
        else:
            return False
```