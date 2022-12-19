class Solution:
    def insert(self, intervals, newInterval):
        rev = []
        for interval in intervals:
            if interval[1] < newInterval[0] or interval[0] > newInterval[1]:
                rev.append(interval)
            else:
                newInterval[0] = min(interval[0], newInterval[0])
                newInterval[1] = max(interval[1], newInterval[1])

        rev.append(newInterval)
        rev.sort(key=lambda x: x[0])

        return rev


