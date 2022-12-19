### 解题思路
while比for+if整洁多了~

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2: return nums # [1] return [1]
        
        i = n-2 # n-2是倒数第二位
        while i>=0 and nums[i+1] <= nums[i]: i -= 1 # 此处i可以等于-1！！！
        
        if i >= 0: # 当i=-1时，则为[5,4,3,2,1]这种情况
            j = n-1 # n-1是最后一位
            while j >= 0 and nums[j] <= nums[i]: j -= 1
            nums[i], nums[j] = nums[j], nums[i] # 在i=-1时不进行转换
            
        self.reverse(nums, i+1, n-1) # 可以确保i=-1时，将[5,4,3,2,1]替换为[1,2,3,4,5]
        return nums
    
    def reverse(self, nums, i, j):
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        return
```