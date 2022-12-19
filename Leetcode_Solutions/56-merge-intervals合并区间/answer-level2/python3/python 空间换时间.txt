### 解题思路
先排序，然后开辟另一个list存储答案，然后注意合并

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        mergred=[]
        intervals.sort()
        if not intervals:
            return []
        mergred.append(intervals[0])
        if len(intervals)==1:
            return mergred
        for i in range(1,len(intervals)):
            if intervals[i][0]>mergred[-1][1]:
                mergred.append(intervals[i])
            elif intervals[i][0]<=mergred[-1][1] and intervals[i][1]>mergred[-1][1]:
              
                mergred[-1][1]=intervals[i][1]
        return mergred
```