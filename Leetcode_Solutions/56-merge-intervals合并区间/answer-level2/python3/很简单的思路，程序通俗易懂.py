def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res=[]
        if len(intervals)<2:
            return intervals
        intervals.sort()    
        tmp=intervals[0]
        for i in range(1,len(intervals)):
            if intervals[i][0]>tmp[1]:
                res.append(tmp)
                tmp=intervals[i]
            elif intervals[i][0]<=tmp[1]:
                tmp=[tmp[0],max(tmp[1],intervals[i][1])]
        res.append(tmp)

        return res