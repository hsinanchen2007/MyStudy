```
import heapq
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        cp = [(Capital[i],Profits[i]) for i in range(len(Profits))]
        heapq.heapify(cp)
       
        pc = []
        while k !=0 :
            while cp and cp[0][0] <= W:
                tmp = heapq.heappop(cp)
                heapq.heappush(pc,(-tmp[1],tmp[0]))
            if len(pc) == 0:
                break
            W += -heapq.heappop(pc)[0]
            k -= 1
        return W
```
