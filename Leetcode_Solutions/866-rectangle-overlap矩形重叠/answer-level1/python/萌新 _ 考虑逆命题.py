### 解题思路
考虑逆命题

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1 == rec2:
            return True

        #left & right
        if rec1[0] <= rec2[0] and rec1[2] <= rec2[0] or \
           rec1[0] >= rec2[2] and rec1[2] >= rec2[2]:
            return False
        #up & down
        if rec1[1] >= rec2[3] and rec1[3] >= rec2[3] or \
           rec1[1] <= rec2[1] and rec1[3] <= rec2[1]:
            return False

        return True

```