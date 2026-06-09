```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        import itertools 
        nums = list(range(1, n+1))
        res = []
        for item in itertools.combinations(nums, k):
            res.append(list(item))
        return res
```
