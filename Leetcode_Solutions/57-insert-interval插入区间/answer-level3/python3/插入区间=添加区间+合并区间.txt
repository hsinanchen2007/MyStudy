### 解题思路
与合并区间那个题目类似，只需要先把新区间加入进来，然后按照区间起始端点排序，最后再合并即可以

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort(key=lambda x:x[0])
        ans = [intervals[0]]
        for i in range(1, len(intervals)):
            if ans[-1][1]<intervals[i][0]:
                ans.append(intervals[i])
            else:
                ans[-1][1] = max(intervals[i][1], ans[-1][1])
        return ans
```