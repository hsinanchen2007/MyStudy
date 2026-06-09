### 解题思路
走一遍然后去补集就完事了

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
        start1=min(start,destination)
        des=max(start,destination)
        return min(sum(distance[start1:des]),sum(distance)-sum(distance[start1:des]))
```