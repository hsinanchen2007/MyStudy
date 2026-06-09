### 解题思路
下面情况属于不重叠：
- rec2的底y坐标>=rec1的顶y坐标
- rec2的顶y坐标<=rec1的底y坐标
- rec2的右x坐标<=rec1的左x坐标
- rec2的左x坐标>=rec1的右x坐标
其余情况均属于重叠！

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return False if rec2[1]>=rec1[3] or rec2[3]<=rec1[1] or rec2[0]>=rec1[2] or rec2[2]<=rec1[0] else True
```