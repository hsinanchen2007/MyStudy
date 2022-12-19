### 解题思路
就是深度学习iou中相交面积的求法

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # 二维转换为一维来做
        # 判断x的交叠
        x0 = max(rec1[0], rec2[0])
        x1 = min(rec1[2], rec2[2])
        y0 = max(rec1[1], rec2[1])
        y1 = min(rec1[3], rec2[3])

        if x0 < x1 and y0 < y1:
            return True
        else:
            return False


```