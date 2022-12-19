### 解题思路
看了官方题解才明白了是什么意思
题不难 但细节很多

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        def reverse(start):
            nonlocal nums
            i, j = start, l-1 
            while i<j: 
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i+1, j-1
        l = len(nums)
        i = l-2
        for i in range(l-2, -1, -1):
            if nums[i]<nums[i+1]:
                j = i+2 # 因为num[i+1]已经确定大于num[i]了
                while j<l and nums[j]>nums[i]: j += 1 # 严格大于!
                nums[i], nums[j-1] = nums[j-1], nums[i]              
                reverse(i+1) # num[i]已经在正确位置, 只reverse i之后元素     
                return 
        reverse(0)
        # nums = nums[::-1] # 这样不会改变nums本身!!!!

```