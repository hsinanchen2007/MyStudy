```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pos1 = 0
        pos2 = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[i], nums[pos2] = nums[pos2], nums[i]
                nums[pos1], nums[pos2] = nums[pos2], nums[pos1]
                pos1 += 1
                pos2 += 1
            elif nums[i] == 1:
                nums[i], nums[pos2] = nums[pos2], nums[i]
                pos2 += 1
```
**算法**

1. 两个指针分别记录第一个‘1’和‘2’的位置；
2. 当扫描到‘0’时，先和第一个‘2’交换位置再和第一个‘1’交换位置；
3. 当扫描到‘1’时，和第一个‘2’交换位置；
4. 更新指针位置。

