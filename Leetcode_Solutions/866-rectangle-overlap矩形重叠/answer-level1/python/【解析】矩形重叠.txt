### 解题思路
两个矩形不重叠的情况有四种：rec1在rec2左侧，rec1在rec2右侧，rec1在rec2上方，rec1在rec2下方。
对应这四种情况写出代码，返回False。其他的情况返回True即可完成。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[2]<=rec2[0] or rec1[0]>=rec2[2] or rec1[1]>=rec2[3] or rec1[3]<=rec2[1]:
            return False
        else:
            return True
```