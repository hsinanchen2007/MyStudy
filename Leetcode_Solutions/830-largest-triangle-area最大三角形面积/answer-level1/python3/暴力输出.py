### 解题思路
此处撰写解题思路

### 代码

```python3
import math
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def area(x,y,z):
            p = (x+y+z)/2
            if x+y >z and y+z > x and x+z > y:
                return (p*(p-x)*(p-y)*(p-z))**0.5
            else :
                return 0
        def distence(l1,l2):
            return ((l1[0]-l2[0])**2 + (l1[1]- l2[1])**2)**0.5
        Max = 0
        for i in range(len(points)):
            for j in range(i , len(points)):
                for k in range(j ,len(points)):
                    x = distence(points[i], points[j])
                    y = distence(points[j], points[k])
                    z = distence(points[k], points[i])
                    Max = max(Max,area(x,y,z))
        return Max
```