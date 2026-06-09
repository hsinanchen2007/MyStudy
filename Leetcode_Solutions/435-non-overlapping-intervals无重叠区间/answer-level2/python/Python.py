### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(intervals)==0:
            return 0
        def takesecond(a):
            return a[1]
        
        intervals.sort(key=takesecond)
        end=intervals[0][1]
        ans=1
        for i in intervals:
            if i[0]<end:
                continue
            else:
                end=i[1]
                ans=ans+1
        return len(intervals)-ans
```