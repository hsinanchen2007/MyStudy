```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l < h:
            m = (l + h) // 2
            if nums[m] < nums[-1]:
                h = m
            else:
                l = m + 1
        return nums[l]
```
-标准二岔二分搜索
- python 二分套路公式：
```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        self.__class__.__getitem__ = lambda self, m: nums[m] <= nums[-1]
        return nums[bisect.bisect_left(self, True, 0, len(nums))]
```
- 公式请参考[我的Github](https://github.com/cy69855522/Shortest-LeetCode-Python-Solutions/blob/master/README.md#-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)