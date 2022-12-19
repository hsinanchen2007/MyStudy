### 解题思路
根据数组中元素的第一个值对数组进行快排，然后判断区间是否重叠，如果有重叠合并区间即可。

### 代码

```python
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(intervals) <= 1:
            return intervals
        def quick_sort(nums, left, right):
            if right - left < 1:
                return
            p, q = left, right
            temp = nums[left]
            while p < q:
                while p < q and nums[q][0] > temp[0]:
                    q -= 1
                if p < q:
                    nums[p] = nums[q]
                    p += 1
                while p < q and nums[p][0] < temp[0]:
                    p += 1
                if p < q:
                    nums[q] = nums[p]
                    q -= 1
            nums[p] = temp
            quick_sort(nums, left, p - 1)
            quick_sort(nums, p + 1, right)

        quick_sort(intervals, 0, len(intervals) - 1)
        res = []
        x, y = intervals[0][0], intervals[0][1]
        for i in range(1, len(intervals)):
            if y < intervals[i][0]:
                res.append([x, y])
                x, y = intervals[i][0], intervals[i][1]
            else:
                x = min([x, y] + intervals[i])
                y = max([x, y] + intervals[i])
        res.append([x, y])
        return res
```