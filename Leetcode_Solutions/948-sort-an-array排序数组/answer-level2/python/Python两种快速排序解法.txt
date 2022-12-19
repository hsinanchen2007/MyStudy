第一种是采用左右指针,第二种是列表切片
```python
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #return self.quick_sort(nums, 0, len(nums) - 1)
        return self.quick_sort(nums)
    '''    
    def quick_sort(self, nums, left, right):
        if left > right:
            return 
    
        if left < right:
            mid = self.partition(nums, left, right)
            self.quick_sort(nums, left, mid-1)
            self.quick_sort(nums, mid+1, right)
        return nums

    def partition(self, nums, left, right):
        tmp = nums[left]
        while left < right:
            while left < right and nums[right] >= tmp:
                right -= 1
            nums[left] = nums[right]
            while left < right and nums[left] <= tmp:
                left += 1
            nums[right] = nums[left]
        nums[left] = tmp
        return left
    '''
    def quick_sort(self, nums):
        if len(nums) < 2:
            return nums
        tmp = nums[0]
        left = [i for i in nums[1:] if i <= tmp]
        right = [i for i in nums[1:] if i > tmp]
        left = self.quick_sort(left)
        right = self.quick_sort(right)
        
        return  left + [tmp] + right
```
