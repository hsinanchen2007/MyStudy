```
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        from collections import Counter
        a = Counter(candies)
        n = len(candies)
        b = 0
        for i in set(candies):
            b += a[i]-1
        # print(b,n-b)
        return n//2 if n//2 < n-b else n-b
        
```
