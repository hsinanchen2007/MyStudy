```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        x=0
        for i,n in enumerate(nums):
            if n%2!=0:
                nums[x],nums[i]=nums[i],nums[x]
                x+=1
        return nums
```
