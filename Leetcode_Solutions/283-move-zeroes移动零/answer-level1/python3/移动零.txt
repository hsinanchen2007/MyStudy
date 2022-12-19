```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        # 遍历列表
        for j in range(len(nums)):
            # 当前元素是否为0，为0查看下一个元素
            if nums[j] != 0:
                # 防止整个列表都为非空，每次都要和自己交换
                if i != j:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
                else:
                    i += 1

        return nums
```
