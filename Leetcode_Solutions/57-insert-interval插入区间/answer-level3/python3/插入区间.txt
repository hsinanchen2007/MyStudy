### 解题思路
和“56.合并区间”思路一致。

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval) 
        intervals = sorted(intervals) 

        result = []
        interLen = len(intervals)

        i = 0
        while i < interLen:
            left = intervals[i][0]
            right = intervals[i][1]
            while i < interLen-1 and intervals[i+1][0] <= right:
                i += 1
                right = max(intervals[i][1], right)
            result.append([left, right])
            i += 1
        return result

```