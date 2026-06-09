### 解题思路
思路与<56区间合并>完全相同，只多了`intervals.append(newInterval)`

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        #区间合并
        intervals.append(newInterval)
        intervals.sort(key=lambda x:x[0])
        itvlen=len(intervals)
        merged=[]
        for i in range(itvlen):
            if not merged or merged[-1][-1]<intervals[i][0]:#无相交
                merged.append(intervals[i])
            else:#右重叠，更新右侧
                merged[-1][-1]=max(merged[-1][-1],intervals[i][-1])
        return merged
```