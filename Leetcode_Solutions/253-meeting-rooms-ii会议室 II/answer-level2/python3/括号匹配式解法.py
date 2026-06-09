### 解题思路
括号匹配式解法

### 代码

```python3
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        result = []
        sum = 0
        for idx, value in enumerate(intervals):
            result.append((value[0], 1))
            result.append((value[1], -1))
        result.sort()
        max_cnt = 0
        for _ in result:
            sum = sum + _[1]
            max_cnt = max(sum, max_cnt)
        return max_cnt
```

执行结果：
通过
显示详情
执行用时 :
76 ms
, 在所有 Python3 提交中击败了
90.48%
的用户
内存消耗 :
16.7 MB
, 在所有 Python3 提交中击败了
64.05%
的用户