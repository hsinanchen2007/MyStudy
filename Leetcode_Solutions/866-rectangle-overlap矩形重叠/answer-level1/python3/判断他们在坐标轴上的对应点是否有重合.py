### 解题思路
有重合的话，重合部分距离小于两个边长分别相加

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x_range1=abs(rec1[2]-rec1[0])
        x_range2=abs(rec2[2]-rec2[0])
        x_range=abs(max(rec1[2],rec2[2])-min(rec1[0],rec2[0]))

        y_range1=abs(rec1[3]-rec1[1])
        y_range2=abs(rec2[3]-rec2[1])
        y_range=abs(max(rec1[3],rec2[3])-min(rec1[1],rec2[1]))

        if (x_range1+x_range2) >x_range and (y_range1+y_range2)>y_range:
            return True
        else:
            return False

```