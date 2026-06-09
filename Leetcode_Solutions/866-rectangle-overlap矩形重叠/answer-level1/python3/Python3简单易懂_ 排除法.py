### 解题思路
矩形1在左边, 在上边, 在下边, 在右边的情况都能排除, 那就重叠了.

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        Ax1, Ay1, Ax2, Ay2 = rec1
        Bx1, By1, Bx2, By2 = rec2
        if Ax2 <= Bx1 or Ax1 >= Bx2 or Ay1 >= By2 or Ay2 <= By1: return False
        return True
```