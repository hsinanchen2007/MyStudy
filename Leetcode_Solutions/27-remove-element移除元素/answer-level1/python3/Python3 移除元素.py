时间复杂度O(n), 空间复杂度O(1)
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        length = len(nums)
        while i<length:
            if nums[i]==val:
                nums.pop(i)
                length = len(nums)
                continue
            i += 1
        return len(nums)
```