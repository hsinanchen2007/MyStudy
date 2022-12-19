```python
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l, r, k = 0, len(nums) - 1, len(nums) - k

        while l <= r:
            x, y = self._partitions(nums, l, r)
            if x <= k <= y:
                return nums[k]
            elif k > y:
                l = y + 1
            else:
                r = x - 1
    
    def _partitions(self, nums, l, r):
        if l >= r:
            return l, r
        
        pivot = random.randint(l, r)
        nums[l], nums[pivot] = nums[pivot], nums[l]

        pivot, i = nums[l], l
        while i <= r:
            if nums[i] == pivot:
                i += 1
            elif nums[i] < pivot:
                nums[i], nums[l], i, l = nums[l], nums[i], i + 1, l + 1
            else:
                nums[i], nums[r], r = nums[r], nums[i], r - 1
        
        return l, i - 1
```

思路：
三路快排，返回当前选择的pivot的范围，返回范围的原因是怕有太多的重复元素，随机选择pivot的目的是怕整个数组是逆序的，然后对于每次划分的范围进行二分搜索。