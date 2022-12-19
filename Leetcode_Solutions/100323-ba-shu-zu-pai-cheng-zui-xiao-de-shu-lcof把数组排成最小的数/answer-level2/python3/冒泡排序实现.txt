借助冒泡排序，首先对其转换为str，前后判断大小，得到字符串nums，输出即可。
```
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        if len(nums) == 0:
            return ""
        for i in range(len(nums)):
            nums[i] = str(nums[i])
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] > nums[j] + nums[i]:
                    nums[i], nums[j] = nums[j], nums[i]
        return "".join(nums)
```
