### 解题思路
此处撰写解题思路
排序 + 线性扫描 Python3
### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []
        
        if len(intervals) == 1:
            return intervals

        intervals.sort()
        
        output = [intervals[0]]
        for i in range(1, len(intervals)):
            if output[-1][1] >= intervals[i][0]:
                output[-1] = [output[-1][0], max(output[-1][1], intervals[i][1])]
            else:
                output.append(intervals[i])
        
        return output

            


```