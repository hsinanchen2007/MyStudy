### 解题思路
> 开始时间排序后， 判定后一个会议开始时间晚于前一个会议的结束时间即可；

### 代码

```python3
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if len(intervals) < 2:
            return True
        intervals.sort(key=lambda p: p[0])
        for i in range(1, len(intervals)):
            if intervals[i][0] < intervals[i - 1][1]:
                return False
        return True
```

### time
```
执行用时 :32 ms, 在所有 Python3 提交中击败了98.94%的用户
内存消耗 :15.2 MB, 在所有 Python3 提交中击败了100.00%的用户
```