```python
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if not intervals:
            return [newInterval]
        
        def find(lis, k, i):
            lefti = 0
            leftj = len(lis) - 1

            while lefti <= leftj:
                mid = (lefti + leftj) // 2
                if lis[mid][i] > k:
                    leftj = mid - 1
                elif lis[mid][i] < k:
                    lefti = mid + 1
                else:
                    return mid
            return lefti

        left = find(intervals, newInterval[0], 0)
        right = find(intervals, newInterval[1], 1)
        
        l = max(left-1, 0)
        r = min(right+1, len(intervals))

        leftlis = intervals[:l]
        rightlis = intervals[r:]
        midlis = intervals[l:r]

        if midlis:
            if newInterval[0] <= midlis[0][1] and newInterval[1] >= midlis[-1][0]:
                midlis = [[min(midlis[0][0], newInterval[0]), max(midlis[-1][1], newInterval[1])]]
            elif newInterval[0] > midlis[0][1] and newInterval[1] >= midlis[-1][0]:
                midlis = [midlis[0], [newInterval[0], max(midlis[-1][1], newInterval[1])]]
            elif newInterval[0] <= midlis[0][1] and newInterval[1] < midlis[-1][0]:
                midlis = [[min(midlis[0][0], newInterval[0]), newInterval[1]], midlis[-1]]
            else:
                midlis = [midlis[0], newInterval, midlis[-1]]
        else:
            midlis = [newInterval]

        ans = leftlis + midlis + rightlis

        return ans
```
采用二分查找找到新插入取间[A,B]， A在所有左侧点中插入位置(或直接命中)，B在所有右侧点中插入位置（或直接命中）  
根据左右侧插入点构建结果