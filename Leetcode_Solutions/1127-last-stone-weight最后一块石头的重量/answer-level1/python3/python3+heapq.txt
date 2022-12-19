```

import heapq
class Solution:
    def lastStoneWeight(self, stones) -> int:
        stonesList=[c*-1 for c in stones]
        heapq.heapify(stonesList) 
        #每个元素存入堆都乘-1，，取出时再乘-1，最小堆就变为最大堆
        while len(stonesList) > 1 :
            x=-1*heapq.heappop(stonesList)
            y=-1*heapq.heappop(stonesList)
            if x > y:
                heapq.heappush(stonesList,y-x)
        if len(stonesList)==1 :
            return -1*stonesList[0]
        return 0
```
