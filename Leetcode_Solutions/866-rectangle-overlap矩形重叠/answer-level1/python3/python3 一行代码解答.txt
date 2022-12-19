### 解题思路
两个矩形的相对位置问题，只需考虑其中一个相对另外一个的位置。
当矩形1与矩形2只存在 相离 和 “相切” 的关系时，两矩形便不重叠，由此有解答如下：

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        
        return False if rec1[0] >= rec2[2] or rec1[2] <= rec2[0] or rec1[1] >= rec2[3] or rec1[3] <= rec2[1] else True
```