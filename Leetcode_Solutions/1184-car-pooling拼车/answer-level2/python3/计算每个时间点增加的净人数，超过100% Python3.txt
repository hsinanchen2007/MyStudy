```
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        onoff = collections.defaultdict(int)
        for v, s, t in trips:
            onoff[s] += v
            onoff[t] -= v

        onoff = [(k, v) for k, v in onoff.items()]
        onoff.sort()

        count = 0
        for t, v in onoff:
            count += v
            if count > capacity:
                return False

        return True
```
