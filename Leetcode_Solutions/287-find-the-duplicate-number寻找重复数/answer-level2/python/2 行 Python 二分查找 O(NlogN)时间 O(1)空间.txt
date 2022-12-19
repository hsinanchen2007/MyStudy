```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        self.__class__.__getitem__ = lambda sef, m: sum(n <= m for n in nums) > m
        return bisect.bisect_left(self, True, 1, len(nums) - 1)
```
- [套路B](https://github.com/cy69855522/Shortest-LeetCode-Python-Solutions/blob/master/README.md#-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)
```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l < h:
            m = (l + h) >> 1
            if sum(n <= m for n in nums) > m:
                h = m
            else:
                l = m + 1
        return l
```
- 本题可用二分查找，整个算法时间复杂度为 O(NlogN)，由题意可知搜索范围在 1 到 n 之间，那么如何缩小范围？只需判断数组中不超过中间数 m 的元素数量是否大于 m 即可，若大于，则表示范围 1 到 m 内肯定包含重复的数字
- 搜索范围为 [1, n]，向左（包括target）搜索的条件为：不大于 n 的数字在 nums 存在超过 m 个，即搜索范围可以被缩小为 [1, m]