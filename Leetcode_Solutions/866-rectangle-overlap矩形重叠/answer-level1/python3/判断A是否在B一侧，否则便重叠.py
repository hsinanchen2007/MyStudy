### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if (rec1[0]<=rec2[0] and rec1[2]<=rec2[0]) or (rec1[0]>=rec2[2] and rec1[2]>=rec2[2]) or (rec1[1]<=rec2[1] and rec1[3]<=rec2[1]) or (rec1[1]>=rec2[3] and rec1[3]>=rec2[3]):
            return False
        else:return True
```