```
import collections
import heapq
class Solution:
    def frequencySort(self, s: str) -> str:
        countFrequency = collections.defaultdict(int)
        for i in s:
            countFrequency[i] += 1
        heap = []
        for i in countFrequency:
            heapq.heappush(heap, (-countFrequency[i], i))
        
        res = []
        for _ in range(len(countFrequency)):
            times,char = heapq.heappop(heap)
            for _ in range(-times):
                res.append(char)
        return ''.join(res)
```

