```
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        num = 0
        i,j = 0,1
        n1 = len(points)
        while j < n1:
            a1 = points[i][0]
            a2 = points[i][1]
            b1 = points[j][0]
            b2 = points[j][1]
            len1 = abs(a1-b1)
            len2 = abs(a2-b2)
            len3 = max(len1,len2)
            num += len3
            i += 1
            j += 1
        return(num)
```
