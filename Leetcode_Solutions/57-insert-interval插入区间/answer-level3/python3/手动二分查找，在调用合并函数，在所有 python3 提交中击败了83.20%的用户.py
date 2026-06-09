思路：
1. 二分查找法，定位插入数组应插入的位置mid：可能与 mid 存在交叉、可能在mid左边or右边；
1. 找到应插入位置mid后，判断应插在左边、右边、与mid存在交叉需要合并；
1. 插入的新数组区间可能很大，此时可能存在重叠区间，调用合并区间函数完成合并。

```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        #合并区间
        def merge(intervals: List[List[int]]) -> List[List[int]]:
            l = len(intervals)
            res = []
            if l == 0:return res

            intervals.sort()               #排序此时仍然不能省略，否则会出现特殊情况
            i = 0
            temp = intervals[0]            #临时区间，记录合并区间的左、右端点

            while i < l-1:            
                if temp[1] >= intervals[i+1][1]:        #左区间覆盖右区间时
                    pass
                elif temp[1] >= intervals[i+1][0]:      #左、右区间交叉时
                    temp[1] = intervals[i+1][1]
                else:
                    res.append(temp)                    #左、右区间不交叉时
                    temp = intervals[i+1]
                i += 1
            res.append(temp)

            return res
        
        #main
        l = len(intervals)
        if l == 0: return [newInterval]
        #二分查找
        left, right = 0, l-1
        mid = (left + right) // 2
        
        while left < right:
            if newInterval[0] > intervals[mid][1]:
                left = mid + 1
                mid = (left + right) // 2
            elif newInterval[1] < intervals[mid][0]:
                right = mid - 1
                mid = (left + right) // 2
            else:
                break
        
        if newInterval[0] > intervals[mid][1]:
            intervals.insert(mid+1, newInterval)
        elif newInterval[1] < intervals[mid][0]:
            intervals.insert(mid, newInterval)
        else:
            intervals[mid][0] = min(intervals[mid][0], newInterval[0])
            intervals[mid][1] = max(intervals[mid][1], newInterval[1])
        
        #调用合并区间函数
        #print(intervals)      #debug
        return merge(intervals)


执行结果：通过显示详情
执行用时 :104 ms, 在所有 python3 提交中击败了83.20%的用户
内存消耗 :17.3 MB, 在所有 python3 提交中击败了5.18%的用户
```
