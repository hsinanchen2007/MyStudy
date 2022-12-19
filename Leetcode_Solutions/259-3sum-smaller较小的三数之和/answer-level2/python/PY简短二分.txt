```
from bisect import bisect_left


class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        n,res=len(nums),0
        nums.sort()
        for i,j in itertools.combinations(range(n),2):
            res+=max(0,bisect_left(nums,target-nums[i]-nums[j])-j-1)
        return res
```
