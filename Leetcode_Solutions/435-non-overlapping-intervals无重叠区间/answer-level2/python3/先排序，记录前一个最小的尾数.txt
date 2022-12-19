### 解题思路
先排序，记录前一个最小的尾数

### 代码

```python3
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: return 0
        intervals.sort(key = lambda x : (x[0], x[1]))
        dp = [1 for _ in range(len(intervals))]
        flag = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= flag:
                dp[i] = dp[i - 1] + 1
                flag = intervals[i][1]
            else:
                dp[i] = dp[i - 1]
                flag = min(intervals[i][1], flag)
        return len(intervals) - dp[len(intervals) - 1]
```