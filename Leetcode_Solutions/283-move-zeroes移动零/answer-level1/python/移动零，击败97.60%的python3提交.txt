解题思路：遍历列表，遇到0就pop到列表尾部。

```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nlen = len(nums)

        i = 0
        while i < nlen:
            if nums[i] == 0:
                nums.append(nums.pop(i))
                nlen -= 1
            else:
                i += 1
        
```
