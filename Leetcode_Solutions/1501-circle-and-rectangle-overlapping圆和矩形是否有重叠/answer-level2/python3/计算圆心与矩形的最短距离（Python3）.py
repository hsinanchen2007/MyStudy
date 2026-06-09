参考评论区提到的解法：[知乎链接](https://www.zhihu.com/question/24251545)
```python
import numpy as np

class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 矩形的中心
        rx, ry = 0.5 * (x1 + x2), 0.5 * (y1 + y2)
        # 矩形的中心指向圆心的向量 v
        v = abs(np.array([x_center-rx, y_center-ry]))
        # 矩形的中心指向矩形右上角的向量 h
        h = np.array([x2 - rx, y2 - ry])

        u = np.maximum(v - h, 0)
        
        return u @ u <= radius**2
```