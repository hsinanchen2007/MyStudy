```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum([nums[x] for x in range(0,len(nums),2)])
```
