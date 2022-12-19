> 贪心思路：两个区间相交时，选择右端最小值作为射箭点（更新当前左区间右端值）
```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:

        points.sort()
        res = 0
        #print(points)

        i,j = 0,1
        while j < len(points):
            if points[i][1] >= points[j][0]:
                points[i][1] = min(points[i][1],points[j][1])
                res += 1
                j += 1
            else:
                i = j
                j += 1
        
        return len(points)-res
```