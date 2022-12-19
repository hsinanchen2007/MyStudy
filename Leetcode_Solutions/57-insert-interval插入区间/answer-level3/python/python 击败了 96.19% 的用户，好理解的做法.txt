class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        #先排序会快很多
        intervals.append(newInterval)
        intervals.sort( key = lambda x: x[0] )
        answer = []
        for interval in intervals:
            if not answer or answer[-1][-1]<interval[0]:
                answer.append(interval)
            else:
                answer[-1][-1] = max(answer[-1][-1],interval[-1])
        return answer