![image.png](https://pic.leetcode-cn.com/fe6b4021e2c33c20306c749abc467f363348a147c28253c7028462111360d0cd-image.png)


```
'''
二分法找要删除的区间的边界
'''

from typing import List
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        intervals.sort(key=lambda x : x[0])
        start, end = toBeRemoved

        # 最左边最后一个起点比左边界小的区间
        l, r = 0, len(intervals)-1
        pos = -1
        while l <= r:
            m = l + (r - l) // 2
            if intervals[m][0] < start:
                pos = m
                l = m + 1
            else:
                r = m - 1

        ans = intervals[:pos] if pos != -1 else []

        if pos != -1:
            if intervals[pos][1] <= start:
                ans.append([intervals[pos][0], intervals[pos][1]])
            else:
                ans.append([intervals[pos][0], start])
                if intervals[pos][1] == end:
                    ans.extend(intervals[pos+1:])
                    return ans

                if intervals[pos][1] > toBeRemoved[1]:
                    ans.append([end, intervals[pos][1]])
                    ans.extend(intervals[pos + 1:])
                    return ans

        suffix_idx = pos + 1
        l, r = pos+1, len(intervals) - 1
        pos = -1
        while l <= r:
            m = l + (r - l) // 2
            if intervals[m][0] < end:
                pos = m
                l = m + 1
            else:
                r = m - 1

        if pos != -1 and intervals[pos][1] > end:
            ans.append([end, intervals[pos][1]])

        if pos != -1:
            ans.extend(intervals[pos+1:])
        else:
            ans.extend(intervals[suffix_idx:])
        return ans
```
