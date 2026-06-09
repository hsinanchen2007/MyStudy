```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination, start
        clockwise_distance = sum(distance[start: destination])
        anticlockwise_distance = sum(distance) - clockwise_distance
        return min(clockwise_distance, anticlockwise_distance)
```
