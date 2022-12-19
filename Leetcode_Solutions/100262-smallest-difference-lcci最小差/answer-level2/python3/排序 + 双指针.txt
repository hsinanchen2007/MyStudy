
```
class Solution:
    def smallestDifference(self, a: List[int], b: List[int]) -> int:
        if not a or not b: return 
        a.sort()
        b.sort()
        p1 = 0
        p2 = 0
        res = float('inf')
        while p1 < len(a) and p2 < len(b):
            res = min(res, abs(a[p1]-b[p2]))
            if b[p2] > a[p1]:
                p1 += 1
            else:
                p2 += 1
        return res
```
