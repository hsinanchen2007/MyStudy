1. 第一遍从后往前找，找到第一个 nums[i] < nums[i + 1]， 记录i的位置
2. 第二遍从后往前找，找到第一个 nums[j] > nums[i], 交换这两个元素
3. 经过前两步之后，我们只需要保持 nums[i:] 逆序即可
```py3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx = len(nums) - 2
        while idx >= 0:
            if nums[idx] < nums[idx + 1]:
                break 
            idx -= 1

        if idx == -1:
            for i in range(len(nums) // 2):
                nums[i], nums[len(nums) - i - 1] = nums[len(nums) - i - 1], nums[i]
            return 
        
        for j in range(len(nums)-1, idx, -1):

            if nums[j] > nums[idx]:
                nums[j], nums[idx] = nums[idx], nums[j]

                break 
        tmp = nums[idx+1:]
        tmp = sorted(tmp, key = lambda x: x)
        nums[idx+1:] = tmp
```