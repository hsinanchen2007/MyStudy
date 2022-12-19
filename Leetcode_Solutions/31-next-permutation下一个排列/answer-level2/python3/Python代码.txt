思路看官方题解的
```python3
class Solution:
    def nextPermutation(self, nums) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        i = length - 1
        while i>0:
            if nums[i]>nums[i-1]:
                j = i+1
                while j<length:
                    if nums[i-1]>=nums[j]:
                        break
                    j+=1
                nums[i-1],nums[j-1] = nums[j-1],nums[i-1]
                break
            i-=1
        nums[i:length] = reversed(nums[i:length])
```