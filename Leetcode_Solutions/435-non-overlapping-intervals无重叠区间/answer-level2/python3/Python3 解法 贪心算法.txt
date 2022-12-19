class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # intervals.sort(key=lambda x:x[1])
        intervals.sort(key=self.takeSecond)
        pre = float('-inf')
        maxNum = 0
        for term in intervals:
            if term[0] >= pre:
                maxNum += 1
                pre = term[1]
        return len(intervals) - maxNum
    
    @staticmethod
    def takeSecond(elem):
        return elem[1]