所求的面积为两个面积之和再减去相交的面积 

相交的面积即为横（竖）坐标中的排序过后的中间两个元素

```
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        if A>=G or C<=E or B>=H or D<=F:
            return (C-A)*(D-B)+(H-F)*(G-E)
        a= sorted([A,C,E,G])
        b= sorted([B,D,F,H])
        return (C-A)*(D-B)+(H-F)*(G-E) - (a[2]-a[1])*(b[2]-b[1])
```
