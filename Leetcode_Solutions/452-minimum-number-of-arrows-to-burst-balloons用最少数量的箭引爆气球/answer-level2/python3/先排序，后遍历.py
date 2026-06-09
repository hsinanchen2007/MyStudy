1. 对 `points` 按 `begin` 进行升序排序
2. 循环遍历 `points` 判断相邻位置的区间是否发生重叠
   - 如果重叠：说明只需要一支箭就可以射穿，并把重叠区间的 `end` 值记录下来，用于比较下一次的区间重叠情况
   - 如果不重叠：需要射出的箭数量 + 1

```python
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        length = len(points)
        if length == 0:
            return 0
        res = 1
        # 排序
        points.sort(key=lambda x: x[0])
        
        end = points[0][1]
        # 遍历
        for i in range(1, length):
            if points[i][0] > end:
                res += 1
                end = points[i][1]
            else:
                end = min(end, points[i][1])
                
        return res
```