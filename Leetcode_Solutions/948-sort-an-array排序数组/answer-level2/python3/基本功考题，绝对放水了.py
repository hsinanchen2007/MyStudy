### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quicksort(nums):
            if len(nums) < 2:
                return nums
            
            pivot = nums[0]
            less = [x for x in nums[1:] if x <= pivot]
            greater = [x for x in nums[1:] if x > pivot]
            return quicksort(less) + [pivot] + quicksort(greater)
        
        if not nums:
            return nums
        return quicksort(nums)
            
            
```