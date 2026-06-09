```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]: 
        n = 2
        res = []
        while target >= n*(n+1)//2:
            if (target - n*(n-1)//2) % n == 0:
                start = (target - n*(n-1)//2) // n
                res.append([x for x in range(start, start+n)])
            n += 1
        return res[::-1]
```
