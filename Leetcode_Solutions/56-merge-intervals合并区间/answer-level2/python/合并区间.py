### 解题思路
先对区间的第一个数进行排序，再判断之后的区间是否重复，如果重复，就合并。

### 代码

```python
def takeFirst(elem):
    return elem[0]

class Solution(object):

    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key = takeFirst)
        n = 0
        while (n<(len(intervals)-1)):
            if (intervals[n][1] >= intervals[n+1][0]) and (intervals[n][1]<intervals[n+1][1]):
                intervals[n] = [intervals[n][0], intervals[n+1][1]]
                del intervals[n+1]
            elif (intervals[n][1] >= intervals[n+1][0]) and (intervals[n][1]>=intervals[n+1][1]):
                intervals[n] = [intervals[n][0], intervals[n][1]]
                del intervals[n+1]
            else:
                n = n + 1
        return intervals
    
        
```