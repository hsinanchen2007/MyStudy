### 思路

**数学**

```
rec1 = [x1, y1, x2, y2], rec2 = [x3, y3, x4, y4]
max(x1, x3) < x < min(x2, x4)
max(y1, y3) < y < min(y2, y4)
```

##### Python3代码

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # 左下角取 max
        x1 = max(rec1[0], rec2[0])
        y1 = max(rec1[1], rec2[1])
        # 右上角取 min
        x2 = min(rec1[2], rec2[2])
        y2 = min(rec1[3], rec2[3])
       
       # 判断是否重叠
        if x1 < x2 and y1 < y2:
            return True
        else:
            return False
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0836-Rectangle-Overlap/0836.py)