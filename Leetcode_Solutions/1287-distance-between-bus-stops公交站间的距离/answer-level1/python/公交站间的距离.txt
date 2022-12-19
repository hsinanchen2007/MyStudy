### 解题思路
环形公交站，一共两条路，两条路距离之和为总距离

### 代码

```python
class Solution(object):
    def distanceBetweenBusStops(self, distance, start, destination):
        total_sum = sum(distance)
        sum1 = 0
        m = min(start,destination)
        n = max(start,destination)
        for i in range(m,n):
            sum1 += distance[i] 
        sum2 = total_sum - sum1
        return min(sum1,sum2)
```