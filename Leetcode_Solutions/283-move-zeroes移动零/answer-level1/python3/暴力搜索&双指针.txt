### 解题思路
解法一：暴力搜，当碰到0，开始在当前位置之后的元素里搜索不为0的数，找到后交换数值，继续向后遍历。
解法二：双指针，快指针指向部位0的元素的位置，然后交换快慢指针的值。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # for i in range(len(nums)):
        #     if nums[i] == 0:
        #          j = i
        #          while j<(len(nums)-1) and nums[j] == 0:
        #              j = j+1
        #          nums[i] = nums[j]
        #          nums[j] = 0
        i = 0
        if len(nums) == 0 or len(nums) == 1:
            return
        j = 1
        while i < len(nums) and j < len(nums):
            print(i,j)
            if nums[j] == 0 and nums[i]==0:
                j = j+1
            elif nums[i] == 0 and nums[j]!= 0:
                nums[i] = nums[j]
                nums[j] = 0
            else:
                i = i+1
                j = j+1
```