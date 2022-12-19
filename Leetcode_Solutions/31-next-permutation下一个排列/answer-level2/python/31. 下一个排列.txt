### 解题思路
从后往前寻找nums[i - 1] < nums[i], i - 1位置即为要替换的位置
将从i到len(nums) - 1位置中大于nums[i - 1]的最小元素与nums[i - 1]交换
然后将从i到len(nums) - 1位置的元素排序
### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) > 1:
            for i in range(len(nums) - 1, 0, -1):
                j = i - 1

                if nums[j] < nums[i]:
                    tmp = i
                    for k in range(len(nums) - 1, j, -1):
                        if nums[j] < nums[k] < nums[tmp]:
                            tmp = k

                    nums[j], nums[tmp] = nums[tmp], nums[j]

                    # 对从j + 1到len(nums) - 1位置的元素做排序
                    for k in range(len(nums) - 1, j + 1, -1):
                        for l in range(k - 1, j, -1):
                            if nums[k] < nums[l]:
                                nums[k], nums[l] = nums[l], nums[k]

                    return nums

            nums.sort()

            return nums
```