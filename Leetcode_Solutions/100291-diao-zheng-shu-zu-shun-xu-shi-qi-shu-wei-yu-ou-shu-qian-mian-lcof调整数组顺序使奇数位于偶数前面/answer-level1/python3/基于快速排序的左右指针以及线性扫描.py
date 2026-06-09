很容易理解的两种方法，我都提供了

```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        res = nums[:]
        left = l = 0
        right = r = len(nums)-1
        pivot = nums[r]
        while l < r:
            while l < r and nums[l]%2!=0:
                l+=1
            nums[r]=nums[l]
            while l <  r and nums[r]%2==0:
                r-=1
            nums[l]=nums[r]
        nums[l]=pivot
        return nums


            

    # def exchange(self, nums: List[int]) -> List[int]:
    #     res = nums[:]
    #     left = 0
    #     right = len(nums)-1
    #     for k,v in enumerate(nums):
    #         if v%2==0:
    #             res[right]=v 
    #             right-=1
    #         else:
    #             res[left]=v
    #             left+=1 
    #     return res
```
