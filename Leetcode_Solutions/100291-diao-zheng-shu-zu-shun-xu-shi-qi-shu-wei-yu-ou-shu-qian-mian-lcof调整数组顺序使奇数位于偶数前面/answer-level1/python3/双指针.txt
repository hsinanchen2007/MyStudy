```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        start = 0 
        end = len(nums) -1
        while start < end:
            while start < end and nums[start] % 2 == 1:
                start += 1
            if start == end : break 
            while start < end and nums[end] %2==0:
                end -= 1
            if start == end : break 
            nums[start], nums[end] = nums[end], nums[start]
            start +=1
            end -=1
        return nums
```
