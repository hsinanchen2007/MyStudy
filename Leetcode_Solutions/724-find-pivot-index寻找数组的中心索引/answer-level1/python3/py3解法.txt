```
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        size = len(nums)
        if size==0:
            return -1
        if size==1:
            return 0
        if sum(nums)-nums[0]==0:
            return 0
        sum_left=nums[0]
        sum_right=sum(nums)-nums[0]-nums[1]
        if sum_left==sum_right:
            return 1
        for i in range(1, len(nums)-1):
            sum_left+=nums[i]
            sum_right-=nums[i+1]
            if sum_left == sum_right:
                return i+1
        return -1
```
