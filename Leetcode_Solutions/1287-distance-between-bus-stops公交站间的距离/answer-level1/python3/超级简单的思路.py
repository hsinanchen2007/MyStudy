如果start>destination，交换一下两个数字
forward：从start加到destination
backward：总数减forward

```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination,start
        forward = sum(distance[start:destination])
        backward = sum(distance) - forward
        return min(forward,backward)
```
