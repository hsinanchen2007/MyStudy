```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        nums_len = len(nums)
        while i < nums_len:
            if val in nums:
                nums.remove(val)
                nums_len -= 1
            else:
                i+=1
        return nums_len
```