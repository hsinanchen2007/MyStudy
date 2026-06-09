```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n1 = 0
        while True:
            try:
                nums[n1]
            except IndexError:
                return(len(nums))
            if nums[n1] == val:
                nums.pop(n1)
            else:
                n1 += 1
```
