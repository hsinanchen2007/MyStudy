### 解题思路
反证法：不相交的情况就很好表达了： 一个矩形在另一个矩形的 上下左右 四个方位

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1 = rec1[2], rec1[3]
        x0, y0 = rec1[0], rec1[1]

        a1, b1 = rec2[2], rec2[3]
        a0, b0 = rec2[0], rec2[1]

        return not (a0 >= x1 or b0 >= y1 or a1 <= x0 or b1 <= y0)
```