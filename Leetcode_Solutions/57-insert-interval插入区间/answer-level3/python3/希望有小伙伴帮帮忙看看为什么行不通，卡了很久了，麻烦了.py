class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        #新区间插入到最开始和最末端的特殊情况
        if newInterval[0]<intervals[0][0] and newInterval[1]<intervals[0][0]:
            intervals.insert(0, newInterval)
            return intervals
        if newInterval[0]>intervals[-1][1] and newInterval[1]>intervals[-1][1]:
            intervals.insert(-1, newInterval)
            return intervals
            
        i = 0
        while(i<n):
            #如果左端点在某个区间内
            if intervals[i][0] <= newInterval[0] <= intervals[i][1]:
                if intervals[i][1] >= newInterval[1]:
                    return intervals
                else:
                    intervals[i][1] = newInterval[1]
                #区间合并
                while(i<n-1):
                    if intervals[i][1] > intervals[i+1][1]:
                        intervals.remove(intervals[i+1])
                        n -= 1
                return intervals
            #如果右端点在某个区间内
            elif intervals[i][0] <= newInterval[1] <= intervals[i][1]:
                intervals[i][0] = newInterval[0]
                while(i>0):
                    if intervals[i][0] < intervals[i-1][0]:
                        intervals.remove(intervals[i-1])
                return intervals
            #如果新区间需要单独插入到两个区间中
            elif intervals[i][1] < newInterval[0] and newInterval[1] < intervals[i+1][0]:
                intervals.insert(i+1, newInterval)
                return intervals
            else:
                i += 1