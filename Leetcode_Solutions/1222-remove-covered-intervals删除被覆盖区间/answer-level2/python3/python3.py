### 解题思路
此处撰写解题思路
### 代码

```python3
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        li = sorted(intervals)
        for i in range(len(li)-1):
            while i+1<len(li) and li[i][1]>=li[i+1][1]:
                li.pop(i+1)
        # print(li)
        return len(li)
```