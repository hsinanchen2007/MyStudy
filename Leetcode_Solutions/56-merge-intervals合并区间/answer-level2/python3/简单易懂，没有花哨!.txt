
1.列表空直接返回；
2.排序；
3.把列表第一个元素存入ans，然后用ans[-1](第一次循环时也就是第一个元素)依次和intervals中第二个元素依次比较可能重叠的部分，重叠就把ans中最后一个元素替换成合并的新区间，否则直接加入ans成为ans[-1]。(重叠部分的比较方法直接看代码，很好理解)
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []

        intervals.sort()
        ans = [intervals[0]]
        for i in range(1, len(intervals)):
            if ans[-1][1] >= intervals[i][0]:
                ans[-1] = [min(ans[-1][0], intervals[i][0]), max(ans[-1][1], intervals[i][1])]
            else:
                ans.append(intervals[i])
        return ans
```
