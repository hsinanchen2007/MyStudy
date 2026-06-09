```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        num = len(nums)
        if nums and k:
            # nums = nums[num-k:num]+nums[:num-k]
            # return nums
            for i in range(k):
                nums.insert(0,nums.pop())
```
开始直接准备return nums[num-k:num]+nums[:num-k]返回了，结果人家不需要返回值，忧伤；
