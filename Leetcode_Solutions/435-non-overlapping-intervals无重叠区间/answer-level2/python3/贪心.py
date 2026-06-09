## 思路:

贪心算法，按右边界进行排序即可，看代码便可明白

## 代码:

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        cur_end = float("-inf")
        num = 0
        for start, end in intervals:
            if start >= cur_end:
                num += 1
                cur_end = end
        return len(intervals) - num 
```

