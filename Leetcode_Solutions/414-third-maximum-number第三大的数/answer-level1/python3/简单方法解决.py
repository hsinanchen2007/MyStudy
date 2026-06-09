先去重，然后排序
```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums=set(nums)
        nums=list(nums)
        l = len(nums)
        if l==1:
            return nums[0]
        if l==2:
            return max(nums[0],nums[1])
        
        nums.sort()
        return nums[l-3]
```