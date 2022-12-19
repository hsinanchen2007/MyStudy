```
代码块
class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        length = len(intervals)
        ans = [-1 for i in range(length)]
        if length < 2:
            return ans
        key = [i for i in range(length)]
        array1 = []
        array2 = []
        for i in range(length):
            array1.append(intervals[i][0])
            array2.append(intervals[i][1])
        dic_low = dict(zip(key, array1))
        dic_low = sorted(dic_low.items(), key=operator.itemgetter(1), reverse=False)
        dic_high = dict(zip(key, array2))
        dic_high = sorted(dic_high.items(), key=operator.itemgetter(1), reverse=False)
        turn1, turn2 = 0, 0
        while turn2 < length:
            if dic_high[turn1][1] > dic_low[turn2][1]:
                turn2 += 1
            else:
                ans[dic_high[turn1][0]] = dic_low[turn2][0]
                turn1 += 1
        return ans
```
