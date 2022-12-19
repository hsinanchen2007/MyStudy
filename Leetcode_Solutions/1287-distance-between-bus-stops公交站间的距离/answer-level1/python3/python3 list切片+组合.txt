简单易懂，这样算暴力破解吗？
### 代码

```python3
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start>destination:
            destination,start=start,destination
        List1=distance[start:destination]
        List2=distance[:start]+distance[destination:]
        return min(sum(List1),sum(List2))

```