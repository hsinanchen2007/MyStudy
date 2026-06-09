### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return not (rec2[3]<=rec1[1] or 
                    rec2[2]<=rec1[0] or
                    rec2[1]>=rec1[3] or
                    rec2[0]>=rec1[2])

# class Solution(object):
#     def isRectangleOverlap(self, rec1, rec2):
#         return not (rec1[2] <= rec2[0] or  # left
#                     rec1[3] <= rec2[1] or  # bottom
#                     rec1[0] >= rec2[2] or  # right
#                     rec1[1] >= rec2[3])    # top
```