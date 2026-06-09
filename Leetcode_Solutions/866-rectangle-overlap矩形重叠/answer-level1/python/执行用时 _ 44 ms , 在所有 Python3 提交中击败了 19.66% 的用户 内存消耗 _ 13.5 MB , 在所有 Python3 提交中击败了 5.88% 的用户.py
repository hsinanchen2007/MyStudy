### 解题思路
先比较两个矩形横坐标之间的关系，若重叠，则一定有一个矩形的左（右）横坐标落在另一个的左右横坐标之内，然后对比纵坐标：若纵坐标中右上角的小于另一个的左下角，或者左下角大于另一个的右上角，则不重叠，否则重叠。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if ((rec2[0] - rec1[0]) * (rec2[0] - rec1[2])) < 0 or ((rec2[2] - rec1[0]) * (rec2[2] - rec1[2])) < 0:
            if max(rec2[1], rec2[3]) <= rec1[1] or min(rec2[1], rec2[3]) >= rec1[3]:
                return False
            else:
                return True
        elif ((rec1[0] - rec2[0]) * (rec1[0] - rec2[2])) < 0 or ((rec1[2] - rec2[0]) * (rec1[2] - rec2[2])) < 0:
            if max(rec1[1], rec1[3]) <= rec2[1] or min(rec1[1], rec1[3]) >= rec2[3]:
                return False
            else:
                return True
```