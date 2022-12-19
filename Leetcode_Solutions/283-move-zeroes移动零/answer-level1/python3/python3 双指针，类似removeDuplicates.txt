
类似removeDuplicates，用双指针
i用于从0开始保存每一个非0元素的index
遍历j，遇到非0元素就与i交换，只有交换之后i才改变index位置+=1

```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
```
