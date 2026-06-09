```python
class Solution:
    def __init__(self):
        self.count = 0
    def search(self, nums: List[int], target: int) -> int:
        #递归的停止条件
        if len(nums) == 0: return 0
        #binary search
        mid = len(nums)//2
        if nums[mid]==target:
            self.count = self.count+1
            self.search(nums[:mid],target)
            self.search(nums[mid+1:],target)
        if nums[mid]<target:
            self.search(nums[mid+1:],target)
        if nums[mid]>target:
            self.search(nums[:mid],target)
        return(self.count)
```