### 解题思路
首先计算正向距离，总计里减去争相距离就是反向距离，返回较小的那一个

### 代码
```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        total=sum(distance)
        p1=min(start,destination)
        p2=max(start,destination)
        d1=sum(distance[p1:p2])
        return min(total-d1,d1)


```
