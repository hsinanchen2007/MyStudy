```python
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # [2, 3] [5, 4], [6, 4], [6, 7]
        # [3, 4, 4, 7, 1, 5, 6, 2, 3, 4, 5] => LIS
        # [3, 4, 5, 6]

        # Time complexity  : O(NlogN)
        # Space complexity : O(N)
        if envelopes == []: return 0
        envelopes.sort(key = lambda x: (x[0], -x[1]))
        tail = []
        res = 0
        for a, b in envelopes:
            index = bisect.bisect_left(tail, b)
            if index == len(tail):
                tail.append(b)
            else:
                tail[index] = min(tail[index], b)
            res = max(res, len(tail))
        return res
```