### 解题思路
反证法，不相交的情况少，
所以考虑不相交的话，工作量会少很多，题目本身不难，但是不用反证法的逆向思维的话，正向考虑会很容易思维混乱
（空间想象不好的话，最好画图帮助分析）
矩阵1只可能在矩阵2的上下左右
### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        res = True

        if (rec2[1] >= rec1[3] or rec1[1] >= rec2[3]):
            res = False
        if (rec1[0] >= rec2[2] or rec1[2] <= rec2[0]):
            res = False
        return res
```