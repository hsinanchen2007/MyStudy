### 解题思路
纯逻辑判断，也是超菜超厉害的了
### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return([newInterval])
        if intervals[-1][1] < newInterval[0]:
            intervals.append(newInterval)
            return(intervals)
        if intervals[-1][1] == newInterval[0]:
            intervals[-1][1] = newInterval[1]
            return(intervals)
        if intervals[0][0]>newInterval[1]:
            intervals.insert(0,newInterval)
            return(intervals)
        if intervals[0][0]==newInterval[1]:
            intervals[0][0]=newInterval[0]
            return(intervals)
        if intervals[0][0]>=newInterval[0] and intervals[-1][1]<=newInterval[1]:
            intervals=[newInterval]
            return(intervals)
        
        if intervals[0][0]>newInterval[0]:
            if intervals[-1][0]<newInterval[1] and intervals[-1][1]>newInterval[1]:
                intervals=[[newInterval[0],intervals[-1][1]]]
                return(intervals)
            for j in range(0,len(intervals)-1):
                if intervals[j][0]<=newInterval[1] and intervals[j][1]>=newInterval[1]:
                    intervals[0][0] = newInterval[0]
                    intervals[0][1] = intervals[j][1]
                    if j==0:
                        return(intervals)
                    else:
                        k = j
                        while k>0:
                            intervals.pop(1)
                            k-=1
                        return(intervals)
                if intervals[j][1]<=newInterval[1] and intervals[j+1][0]>=newInterval[1]:
                    intervals[0][0] = newInterval[0]
                    intervals[0][1] = newInterval[1]
                    if j==0:
                        return(intervals)
                    else:
                        k = j
                        while k>0:
                            intervals.pop(1)
                            k-=1
                            return(intervals)
        
        if intervals[-1][0] < newInterval[0]:
            if intervals[-1][1]>newInterval[1]:
                return(intervals)
            else:
                intervals[-1][1]=newInterval[1]
                return(intervals)
            
        for i in range(0,len(intervals)-1):
            if intervals[i][0]<=newInterval[0] and intervals[i][1]>=newInterval[0]:
                if intervals[-1][0]<=newInterval[1] and intervals[-1][1]>=newInterval[1]:
                    intervals[i][1]=intervals[-1][1]
                    k=len(intervals)-i-1
                    while k>0:
                        intervals.pop(i+1)
                        k-=1
                    return(intervals)
                if intervals[-1][1] <= newInterval[1]:
                    intervals[i][1] = newInterval[1]
                    k=len(intervals)-i-1
                    while k>0:
                        intervals.pop(i+1)
                        k-=1
                    return(intervals)
                
                for j in range(i,len(intervals)-1):
                    if intervals[j][0]<=newInterval[1] and intervals[j][1]>=newInterval[1]:
                        intervals[i][1] = intervals[j][1]
                        k = j-i
                        while k>0:
                            intervals.pop(i+1)
                            k-=1
                        return(intervals)
                    if intervals[j][1]<=newInterval[1] and intervals[j+1][0]>newInterval[1]:
                        intervals[i][1] = newInterval[1]
                        k = j-i
                        while k>0:
                            intervals.pop(i+1)
                            k-=1
                        return(intervals)
                    
            if intervals[i][1]<newInterval[0] and intervals[i+1][0]>=newInterval[0]:
                if intervals[-1][0]<newInterval[1] and intervals[-1][1]>=newInterval[1]:
                    intervals[i+1][0] = newInterval[0]
                    intervals[i+1][1]=intervals[-1][1]
                    k=len(intervals)-i-2
                    while k>0:
                        intervals.pop(i+2)
                        k-=1
                    return(intervals)
                if intervals[-1][1] <= newInterval[1]:
                    intervals[i+1][0] = newInterval[0]
                    intervals[i+1][1] = newInterval[1]
                    k=len(intervals)-i-2
                    if i == len(intervals)-2:
                        return(intervals)
                    else:
                        while k>0:
                            intervals.pop(i+2)
                            k-=1
                        return(intervals)
                
                for j in range(i,len(intervals)-1):
                    if intervals[j][0]<=newInterval[1] and intervals[j][1]>=newInterval[1]:
                        intervals[i+1][0] = newInterval[0]
                        intervals[i+1][1] = intervals[j][1]
                        k = j-i-1
                        while k>0:
                            intervals.pop(i+2)
                            k-=1
                        return(intervals)
                    if intervals[j][1]<=newInterval[1] and intervals[j+1][0]> newInterval[1]:
                        if i==j:
                            intervals.insert(i+1,newInterval)
                            return(intervals)
                        else:
                            intervals[i+1][0] = newInterval[0]
                            intervals[i+1][1] = newInterval[1]
                            k = j-i
                            if k==1:
                                return(intervals)
                            else:
                                while k>0:
                                    intervals.pop(i+2)
                                    k-=1
                                return(intervals)
```