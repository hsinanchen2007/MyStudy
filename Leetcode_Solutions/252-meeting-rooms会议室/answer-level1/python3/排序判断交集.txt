### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if not intervals:
            return True
        # 其实这个题的意思就是判断交集吧
        intervals = sorted(intervals, key=lambda x: (x[0], x[1]))
        print(intervals)
        left, right = intervals[0][0], intervals[0][1]
        # 目标就是要让所有的都没有交集
        # left肯定是小的
        for i in range(1, len(intervals)):
            cur_left = intervals[i][0]
            cur_right = intervals[i][1]
            if right > cur_left:
                return False
            left = cur_left
            right = cur_right
        return True
```