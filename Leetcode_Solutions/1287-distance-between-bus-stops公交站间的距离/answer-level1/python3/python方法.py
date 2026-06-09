![1148.png](https://pic.leetcode-cn.com/f9cff28a232fc8d41ea89df632e5e701c4eacfa795f961affe4cd2d53c660455-1148.png)
```
class Solution:
    def distanceBetweenBusStops(self, distance: [int], start: int, destination: int) -> int:
        a=sum(distance)
        if destination<start:
            destination,start=start,destination
        sum1=sum(distance[start:destination])
        print(min(sum1,a-sum1))
```

