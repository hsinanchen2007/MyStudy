```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cur = len(nums) - 2
        while cur >= 0:
            if nums[cur] < nums[cur + 1]:break
            cur -= 1
        if cur == -1: nums.sort()
        else:
            index = len(nums) -1
            while index > cur:
                if nums[index] > nums[cur]:
                    nums[cur], nums[index] = nums[index], nums[cur]
                    nums[cur + 1:] =  sorted(nums[cur + 1:])
                    break
                index -= 1
```