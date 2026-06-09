### 解题思路
反正就是顺时针或者逆时针

### 代码

```python
class Solution(object):
    def distanceBetweenBusStops(self, distance, start, destination):
        """
        :type distance: List[int]
        :type start: int
        :type destination: int
        :rtype: int
        """
        totalDistance = sum(distance)
        if start < destination:
            minIdx, maxIdx = start, destination
        else:
            minIdx, maxIdx = destination, start
        halfSum = sum(distance[minIdx: maxIdx])
        return min(halfSum, totalDistance-halfSum)

```