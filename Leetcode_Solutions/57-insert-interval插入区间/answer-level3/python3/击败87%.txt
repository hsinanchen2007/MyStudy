```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if intervals == []:
            intervals.append(newInterval)
            return(intervals)
        if intervals[0][0] >= newInterval[0] and intervals[-1][-1] <= newInterval[1]:
            return([newInterval])
        list1,list2,list3 = [],[],[]
        for i in intervals:
            if i[0] > newInterval[1]:
                break
            elif i[0] == newInterval[1]:
                list1.append(i)
                break
            elif i[0] < newInterval[1] <= i[1]:
                if i[0] <= newInterval[0]:
                    return(intervals)
                else:
                    list1.append(i)
                    break
            elif newInterval[0] <= i[1] < newInterval[1]:
                list1.append(i)
        if list1 == []:
            if newInterval[0] < intervals[0][0]:
                intervals.insert(0,newInterval)
                return(intervals)
            else:
                n1 = len(intervals)
                for ii in range(n1):
                    if intervals[ii][0] > newInterval[1]:
                        intervals.insert(ii,newInterval)
                        return(intervals)
                intervals.append(newInterval)
                return(intervals)
        else:
            list1.append(newInterval)
            for k in list1:
                for j in range(k[0],k[1]+1):
                    if j not in list2:
                        list2.append(j)
            list2.sort()
            list3 = [list2[0],list2[-1]]
        aa = intervals.index(list1[0])
        intervals.insert(aa,list3)
        for i in range(len(list1)-1):
            intervals.remove(list1[i])
        return(intervals)
```
