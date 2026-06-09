```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        return list(set([tuple(itertools.compress(sorted(nums), j)) for j in [map(int, i) for i in list(itertools.product('01', repeat=len(nums)))]]))
```
