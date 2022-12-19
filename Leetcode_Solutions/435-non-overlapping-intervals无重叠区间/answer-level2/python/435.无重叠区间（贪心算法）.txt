### 解题思路
贪心算法，每次保证最小量的局部最优解，结果就是全局最优解
1. 将所有区间按右边界排序
2. curr区间作为指针，cur_end从负无穷开始（float("-inf")）
3. 只要cur_end<=区间左边界，该区间保留，且替换cur_end为该区间右边界

### 代码

```python
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        intervals.sort(key=lambda x:x[1])
        cur_end = float("-inf")
        num = 0
        for start,end in intervals:
            if cur_end <= start:
                cur_end = end
                num += 1
            else:
                pass
        return len(intervals) - num

```