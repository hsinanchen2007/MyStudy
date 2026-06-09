方法一把列表为[]的情况单独出来了，用计数的方式操作

```
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        # 1. sliding-window operation
        # if not nums:
        #     return 0
        # ans = count = 1
        # for i in range(len(nums)-1):
        #     if nums[i+1] > nums[i]:
        #         count += 1
        #     else:
        #         count = 1
        #     ans = max(ans, count)
        # return ans
    
        # 2. simplified sliding-window operation
        ans = anchor = 0
        for i in range(len(nums)):
            if i and nums[i-1] >= nums[i]:
                anchor = i
            ans = max(ans, i-anchor+1)
        return ans
```
