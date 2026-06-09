#看题，说的是要按照点出现的顺序访问，就变成了两点间最近的走法
#然后两点间最快的走法，题说走横竖和走斜线一样时间，
#画个图就能明白两点间最短就是横坐标与纵坐标差值的最大

``
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        s =  0
        for i in range(len(points)-1):
            s+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]))
        return s
```
