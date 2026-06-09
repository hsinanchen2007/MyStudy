class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        intervals.append(newInterval)
        intervals.sort()
        r = [intervals[0]]
        for s in intervals[1:]:
            last = r[-1][1]
            if last < s[0]:
                r.append(s)
            else:
                r[-1][1] = max(last, s[1])

        return r