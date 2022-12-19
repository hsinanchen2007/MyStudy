### 解题思路
考虑一个矩形的上下左右四个区域就行了
这就简单的离谱...
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return not (rec1[0]>=rec2[2] or rec1[2]<=rec2[0] or rec1[1]>=rec2[3] or rec1[3]<=rec2[1])
```