语言：python
第一种：采用双指针,使得数组中与目标相同的元素全放到数组后方。运行到代码的return left就能返回剩下数组的长度，return left之后是为了返回剩余的数组元素
```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left < right:
            if nums[left] == val and nums[right] != val:
                nums[left],nums[right] = nums[right],nums[left]
                left += 1
                right -= 1
            elif nums[right] == val:
                right -= 1
            elif nums[left] != val:
                left += 1
       #return left
        res = 0
        for i in range(len(nums)):
            if nums[i] != val:
                res += 1
            else:
                return res
```
第二种方法，直接移除与目标相等的元素
```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        while True:
            if val in nums:
                nums.remove(val)
            else:
                break
        return len(nums)
```