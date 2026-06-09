### 解题思路
RT

### 代码

```python
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        result=[]
        for one in timePoints:
            hour,minute=one.split(':')
            hour,minute=int(hour),int(minute)
            result.append(hour*60+minute)
        result.sort()
        final=1000
        print result
        for i in range(1,len(result)):
            final=min(final,result[i]-result[i-1])
        final=min(final,result[0]+1440-result[-1])
        return final
```