```
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if duration == 0:
            return(0)
        elif duration == 1:
            set1 = set(timeSeries)
            return(len(set1))
        if timeSeries == []:
            return(0)
        if timeSeries[-1] < duration:
            return(timeSeries[-1]+duration-timeSeries[0])
        len1 = len(timeSeries)
        num = len1
        i,j = 0,1
        while j < len1:
            if timeSeries[j] - timeSeries[i] >= duration:
                num = num + duration - 1
                i += 1
                j += 1
            elif timeSeries[j] - timeSeries[i] < duration:
                count1 = timeSeries[j] - timeSeries[i] - 1
                num += count1
                i += 1
                j += 1
        num = duration + num -1
        return(num)
                
            
```
