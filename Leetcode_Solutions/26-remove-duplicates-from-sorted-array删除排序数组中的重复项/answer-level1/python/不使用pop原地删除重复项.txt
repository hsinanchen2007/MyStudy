如下简单易懂
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:return 0
        l=len(nums)
        start=1
        while start<l:
            if nums[start] ==nums[start-1]:
                l-=1
                nums[start:l]=nums[start+1:l+1]
            else:
                start+=1
        return l
```
