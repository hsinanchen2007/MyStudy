```
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        wc = collections.Counter(ages)
        uages = list(sorted(wc.keys()))
        
        return sum([((wc[a] * (wc[a]-1) if a >= 15 else 0) +
                    wc[a] * sum([wc[b] for b in uages[bisect.bisect_left(uages, a//2+8): bisect.bisect_right(uages, a-1)]])
                     ) if wc[a] > 0 else 0
                    for a in uages])
```
