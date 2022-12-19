### 解题思路
 思路：两个矩阵分别投影到x轴 y轴，出现四种情况是不重叠的。y轴是上下,x轴是左右的情况。排除这四种情况就是有重叠的。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if not rec1 or not rec2:
            return False
        # x投影的两个不相交的情况 排除两个不相交 就是相交
        # 一左一右
        x_overlap=not(rec1[2]<=rec2[0] or rec2[2]<=rec1[0])
        # y投影的两个不相交的情况 排除两个不相交 就是相交
        # 一上一下
        y_overlap=not(rec1[3]<=rec2[1] or rec1[1]>=rec2[3] )
        return x_overlap and y_overlap
```