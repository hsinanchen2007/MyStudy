### 解题思路
利用区间求值
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return not(rec1[0] >= rec2[2] or rec1[2]<= rec2[0]) and not(rec1[1]>=rec2[3] or rec1[3] <= rec2[1])

```