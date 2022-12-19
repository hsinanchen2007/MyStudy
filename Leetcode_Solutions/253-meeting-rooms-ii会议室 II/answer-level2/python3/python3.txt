```
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[0])
        ans = [intervals[0][1]]
        count = 1
        for i in range(1, len(intervals)):
            tmp = ans[0]
            if intervals[i][0] >= tmp:
                ans.pop(0)
            else:
                count += 1
            ans.append(intervals[i][1])
            ans.sort()
        return count
```
