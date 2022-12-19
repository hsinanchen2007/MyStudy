```
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        # 和之前判断重叠很类似，找到重叠的x范围和重叠y的范围，求出重叠区域即可
        rec1_x = A,C
        rec1_y = B,D

        rec2_x = E,G
        rec2_y = F,H

        # 这里确定是左下顶点和右上顶点构成的，所以这里A<C...
        def helper(range1,range2):
            b1,t1 = range1
            b2,t2 = range2

            if t2<=b1 or t1<=b2:
                return 0
            else:
                return min(t1,t2)-max(b1,b2)
        
        return (C-A)*(D-B)+(G-E)*(H-F)-helper(rec1_x,rec2_x) * helper(rec1_y,rec2_y)
        
```

