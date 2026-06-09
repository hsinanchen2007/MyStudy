```
class Solution(object):
    def wiggleSort(self, nums):
        nums.sort(reverse=True)
        for i in range(len(nums)-1):
            if i%2==0:
                nums[i],nums[i+1]=nums[i+1],nums[i]
        return nums
```
