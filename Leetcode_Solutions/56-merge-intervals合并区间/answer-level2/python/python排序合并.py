执行用时 :84 ms, 在所有 Python 提交中击败了94.73%的用户

内存消耗 :14.4 MB, 在所有 Python 提交中击败了100.00%的用户

首先排序，整个数组进行排序；设置begin和end为一个区间最大的范围，设置计数i依次遍历数组，分以下几种情况：

1、intervals[i][0] > end,说明已经找到了最大的范围，这个时候将范围加入到结果集中，然后重置begin和end；

2、intervals[i][0] > end，这个时候还需要分两种情况；

    1）一种是如果intervals[i][1] > end，说明可以扩充集合，则重置end；然后继续
    2）一种是如果intervals[i][1] <= end，说明这个范围是[begin, end]的子集，可以直接继续

最后需要再添加上最后的一个[begin, end]这个范围就好；
```
class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if intervals == []:
            return []
        intervals.sort()
        begin = intervals[0][0]
        end = intervals[0][1]
        print(intervals)
        res = list()
        for i in range(1, len(intervals)):
            if intervals[i][0] > end:
                res.append([begin, end])
                begin = intervals[i][0]
                end = intervals[i][1]
            else:
                if intervals[i][1] > end:
                    end = intervals[i][1]
        res.append([begin, end])
        return res
```
