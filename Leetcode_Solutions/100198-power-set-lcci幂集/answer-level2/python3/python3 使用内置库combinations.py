```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        import itertools 
        res = [[],]
        for i in range(1,len(nums)+1):
            for item in itertools.combinations(nums, i):
                res.append(list(item))
        return res
```
