### 解题思路
但是为什么效率这么低呢。52ms
### 代码
```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ind = 0
        while ind < len(nums):
            if nums[ind]==val: nums.pop(ind)
            else:ind += 1
```