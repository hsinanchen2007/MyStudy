对于两个一维区间，(a,b)和(c,d)，没有交集的条件是a>=d或者c>=b，延伸到二维空间亦是如此。
```
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec1[0]>=rec2[2] or rec1[1]>=rec2[3] or rec2[0]>=rec1[2] or rec2[1]>=rec1[3]:
            return False
        return True
```
