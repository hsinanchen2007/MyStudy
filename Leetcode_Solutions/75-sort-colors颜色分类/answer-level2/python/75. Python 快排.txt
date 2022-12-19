### 解题思路
排序问题还是原地排序优先想到快排。

### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        def quick_sort(nums, left, right):
            if right - left < 1:
                return 
            p, q = left, right
            temp = nums[left]
            while p < q:
                while p < q and nums[q] > temp:
                    q -= 1
                if p < q:
                    nums[p] = nums[q]
                    p += 1
                while p < q and nums[p] < temp:
                    p += 1
                if p < q:
                    nums[q] = nums[p]
                    q -= 1
            nums[p] = temp
            quick_sort(nums, left, p - 1)
            quick_sort(nums, p + 1, right)
        quick_sort(nums, 0, len(nums) - 1)


```