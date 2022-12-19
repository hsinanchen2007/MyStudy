先把数组排列，然后把第一个如果后一个list和后一个list重合，就要新开一个房间。这时有两个房间，每一个房间作为一个list加入字典，对于后面的list，如果和已有房间中的最后一个list不重合，就可以共用这个房间，把这个list加入到这个房间。
```
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x:x[0])
        count=1
        dic={}
        dic['rooms%d'%count]=[intervals[0]]
        for i in range(1,len(intervals)):
            n=count
            #print('a',dic,intervals[i])
            for n in range(n,-1,-1):
                if n==0:
                    #print('b')
                    count+=1
                    dic['rooms%d'%count]=[intervals[i]]
                    break
                elif dic['rooms%d'%n][-1][1]<=intervals[i][0]:
                    dic['rooms%d'%n].append(intervals[i])

                    #print(n,dic)
                    break
                elif dic['rooms%d'%n][-1][1]>intervals[i][0]:
                    n-=1
        
                
##        return count
```
