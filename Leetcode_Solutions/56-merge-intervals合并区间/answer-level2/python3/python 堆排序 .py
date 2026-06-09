import heapq
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        length = len(intervals)
        #heapq.heapify(intervals)
        intervals = heapq.nsmallest(length, intervals, lambda x: x[0])       
        #print(intervals)
        ret = []
        for i in range(length):
            if len(ret) == 0: 
                ret.append(intervals[i])
                continue
            last = ret[-1]
            if last[0] <= intervals[i][0] <= last[1]:
                if intervals[i][1] > last[1]:
                    ret.pop()
                    ret.append([last[0], intervals[i][1]])
            else:
                ret.append([intervals[i][0], intervals[i][1]])
            
        return ret