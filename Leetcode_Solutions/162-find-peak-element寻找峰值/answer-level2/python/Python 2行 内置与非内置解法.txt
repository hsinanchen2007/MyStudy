```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        self.__class__.__getitem__ = lambda self, m: m and nums[m-1] > nums[m]
        return bisect.bisect_left(self, True, 0, len(nums)) - 1
```
- 改造了类getitem函数以模拟序列，然后使用内置bisect函数搜索
```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l <= h:
            m = (l + h) // 2
            if (not m or nums[m-1] < nums[m]) and (m == len(nums) - 1 or nums[m] > nums[m+1]):
                return m
            elif not m or nums[m] > nums[m-1]:
                l = m + 1
            else:
                h = m - 1
```
- 标准的三岔二分搜索