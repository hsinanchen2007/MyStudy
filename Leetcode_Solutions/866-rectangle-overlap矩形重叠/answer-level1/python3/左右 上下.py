### 解题思路
找出左右，找出上下
完了

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[0] > rec2[0]:
            left = rec2
            right = rec1
        else:
            left = rec1
            right = rec2 
        if rec1[1] < rec2[1]:
            down = rec1
            up = rec2
        else:
            down = rec2
            up = rec1
        if right[0]>=left[2]:
            return False
        else:
            if up[1]>=down[3]:
                return False
            else :
                return True
        


```