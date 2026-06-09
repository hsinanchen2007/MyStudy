执行用时 :60 ms, 在所有 Python3 提交中击败了97.54%的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def distanceBetweenBusStops(self, distance, start, destination):
        sum_distance = sum(distance)
        if start <= destination:
            first_distance = sum(distance[start:destination])
        else:
            first_distance = sum(distance[destination:start])
        return min(first_distance, sum_distance-first_distance)
```
