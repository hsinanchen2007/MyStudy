```
class Solution:
    def merge(self, A: List[List[int]]) -> List[List[int]]:
        if len(A) == 0:  # corner case，空列表
            return []
        intervals = []
        for i in range(len(A)): # 排除列表中有空列表
            if len(A[i]) > 0:
                intervals.append(A[i])
        intervals.sort(key=lambda seq: seq[0]) # 按区间的起始点排序，只用比较区间的终点就可以合并区间
        start = intervals[0][0] # start指针指向区间起点
        end = intervals[0][1] # end指针指向区间终点
        res = []
        for i in range(1, len(intervals)):
            if end < intervals[i][0]: # end指针比下一个区间的起点小， 则已经产生了一个新的合并区间，加入res， 更新start，end为列表中下个区间的起点和终点
                res.append([start, end])
                start = intervals[i][0]
                end = intervals[i][1]
            elif end >= intervals[i][0] and end <= intervals[i][1]: # 当前的end指针在当前区间里，将end指针更新为当前区间的终点 
                end = intervals[i][1]
            elif end > intervals[i][1]: #当前end指针包括了当前区间，处理下一个区间
                continue
        res.append([start, end]) # 这一句重要！ 上面遍历完成之后可能没有把最后一个区间加入res中
        return res

```
