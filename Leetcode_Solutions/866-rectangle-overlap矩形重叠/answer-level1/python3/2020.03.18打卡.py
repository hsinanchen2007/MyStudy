### 解题思路
先判断矩阵2在矩阵1周边的情况，再反向判断。

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec2[0]<rec1[2] and rec2[2]>rec1[0] and rec2[1]<rec1[3] and rec2[3]>rec1[1]:
            return True
        else:
            return False
```