若不满足非递减数列，有两种操作方法：
1. 将该项赋值为后一项的值
2. 将后一项赋值为该项的值
若两种操作后仍不满足，则无法实现
```
class Solution:
    def checkPossibility(self, nums) -> bool:
        if len(nums) < 3:
            return True
        n = 0
        nums1 = nums.copy()
        flag = True
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                nums[i] = nums[i + 1]
                n += 1
                if i > 0 and nums[i] < nums[i - 1]:
                    flag = False
                    break
        if n <= 1 and flag:
            return True
        n = 0
        for i in range(len(nums1) - 1):
            if nums1[i] > nums1[i + 1]:
                nums1[i + 1] = nums1[i]
                n += 1
        if n <= 1:
            return True
        else:
            return False

```
