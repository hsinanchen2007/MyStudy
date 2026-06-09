
```python []
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        result = 0
        for i in range(len(points)):
            x1,y1 = points[i][0],points[i][1]
            for j in range(i+1,len(points)):
                x2,y2 = points[j][0],points[j][1]
                for k in range(j+1,len(points)):
                    x3,y3 = points[k][0],points[k][1]
                    result = max(result,abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)/2)
        return result
```

