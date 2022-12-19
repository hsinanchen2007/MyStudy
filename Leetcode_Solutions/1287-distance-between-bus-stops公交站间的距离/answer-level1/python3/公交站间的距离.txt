### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start < destination:
            return min(sum(distance[start:destination]), sum(distance) - sum(distance[start:destination]))
        else:
            return min(sum(distance[destination:start]), sum(distance) - sum(distance[destination:start]))
```