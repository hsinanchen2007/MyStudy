```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.append(-1)
        res = nums[:]

        for num in nums:
            if num>0 and num<len(res):
                res[num] = nums[num]+1
        for i in range(1,len(res)):
            if res[i] == nums[i]:
                return i
```