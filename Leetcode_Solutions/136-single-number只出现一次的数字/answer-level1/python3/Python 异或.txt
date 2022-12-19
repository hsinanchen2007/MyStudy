思路：使用异或的性质a^b^a = b，即异或具有去重的性质
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums[0]
        for i in range(1,len(nums)):
            res = res ^ nums[i]
        return res
```

