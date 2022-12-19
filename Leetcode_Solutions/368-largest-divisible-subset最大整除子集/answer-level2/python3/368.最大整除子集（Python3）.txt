```
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # nums[i]:可整除nums[i]的数的集合，比如S = {-1:set(),1:{1,2}}
        S = {-1:set()} 
        for x in sorted(nums):
            S[x] = max((S[d] for d in S if x % d == 0),key = len) | {x}
        return list(max(S.values(),key = len))

```

