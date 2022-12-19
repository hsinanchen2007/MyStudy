```
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        a=((points[1][1]-points[0][1])**2 + (points[1][0]-points[0][0])**2)**0.5
        b=((points[1][1]-points[2][1])**2 + (points[1][0]-points[2][0])**2)**0.5
        c=((points[2][1]-points[0][1])**2 + (points[2][0]-points[0][0])**2)**0.5
        res=[a,b,c]
        res.sort()
        return not res[1]+res[0]==res[2]
```
