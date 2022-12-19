```
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        for num in nums:
            if num in hashmap:
                hashmap[num]+=1
            else:
                hashmap[num] = 1
        heap=[]
        for i in set(nums):
            heapq.heappush(heap, (-hashmap[i],i))
        res=[]
        i=1
        while i<=k:
            _, ans = heapq.heappop(heap)
            res.append(ans)
            i+=1
        return res
```
