```
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        t = set(candies)
        return min(len(t),int(len(candies)/2))
```
