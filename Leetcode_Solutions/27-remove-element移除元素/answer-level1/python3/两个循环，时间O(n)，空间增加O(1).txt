第一个循环先把val值排到后面，第二个循环计数非val值
```
class Solution:
    def removeElement(self, nums: list, val: int) -> int:
        my_count = 0
        for i in range(len(nums)):
            if nums[i] == val:
                nums.append(val)
                nums.remove(nums[i])
        for j in range(len(nums)):
            if nums[j] != val:
                my_count += 1

        return my_count
```
