### 解题思路
首先明确什么情况才会重叠

矩形 rec1 在矩形 rec2 的左侧；
矩形 rec1 在矩形 rec2 的右侧；
矩形 rec1 在矩形 rec2 的上方；
矩形 rec1 在矩形 rec2 的下方。

翻译一下就是：

rec1[2] <= rec2[0] 
rec1[3] <= rec2[1]
rec1[0] >= rec2[2]
rec1[1] >= rec2[3]

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return not (rec1[2] <= rec2[0] or  # left
                    rec1[3] <= rec2[1] or  # bottom
                    rec1[0] >= rec2[2] or  # right
                    rec1[1] >= rec2[3])    # top
```