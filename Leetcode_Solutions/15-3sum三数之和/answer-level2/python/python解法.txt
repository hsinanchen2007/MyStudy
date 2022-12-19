

```python []
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        if len(nums) < 3:
            return []
        
        nums.sort()                      
        
        res = set()
        for i, val in enumerate(nums[:-2]):
            
            left = i + 1
            right = len(nums) - 1  # TODO
            while left < right:
                sum = val + nums[left] + nums[right]
                if sum == 0:
                    res.add((val, nums[left], nums[right]))
                    if nums[left] == nums[right]:
                        break
                    left += 1
                    right -= 1
                elif sum > 0:
                    right -= 1
                else:
                    left += 1                                 
                          
        return res
```
