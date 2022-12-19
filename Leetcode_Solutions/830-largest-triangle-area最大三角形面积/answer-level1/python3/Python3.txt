![812.jpg](https://pic.leetcode-cn.com/db7dcbd98436d8161402a82affe88892b1454549e63227eff23ce506976d5d3f-812.jpg)

```
def getTriArea(a,b,c):
    return abs(
            a[0]*(b[1]-c[1])  # x1y2-x1y3
            +b[0]*(c[1]-a[1]) # +x2y3-x2y1
            +c[0]*(a[1]-b[1]) # +x3y1-x3y2
            )/2        #*(1/2)

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max((getTriArea(*i) for i in itertools.combinations(points,3)))
```
