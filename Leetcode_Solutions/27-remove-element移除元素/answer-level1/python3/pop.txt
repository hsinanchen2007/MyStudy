将数组每个数扫描一遍，符合条件的就直接pop出去。
```python []
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i=0
        while i < len(nums):
            if nums[i] == val:
                nums.pop(i)
            else:
                i+=1
        return len(nums)
```
