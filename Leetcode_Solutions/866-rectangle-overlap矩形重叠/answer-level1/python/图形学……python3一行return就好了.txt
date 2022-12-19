### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return (rec1[0]-rec2[2])*(rec1[2]-rec2[0])<0 and (rec1[1]-rec2[3])*(rec1[3]-rec2[1])<0
```