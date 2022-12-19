### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = len(nums)-2
        while i >=0 and nums[i+1] <= nums[i]:
            i -= 1
        if i >= 0:
            j = len(nums) -1
            while j >= i and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        nums[i+1:] = nums[i+1:][::-1]

    # def reverse(self, nums,start):
    #     nums[start:] = nums[start:][::-1]
    # def swap(self,nums,i,j):
    #     nums[i], nums[j] = nums[j], nums[i]

        

```