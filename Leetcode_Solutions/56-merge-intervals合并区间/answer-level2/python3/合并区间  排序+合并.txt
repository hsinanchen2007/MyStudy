思路：
1. 首先对集合进行排序，intervals.sort( )按照每个数组的首个数字排序；
2. 考虑前一区间、后一区间的重叠关系：“交叉”、“覆盖”
3. 使用一临时区间temp记录合并后的左右端点，合并时更新temp的右端点即可。

```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        l = len(intervals)
        res = []
        if l == 0:return res
        
        intervals.sort()
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

执行结果：通过显示详情
执行用时 :108 ms, 在所有 python3 提交中击败了91.96%的用户
内存消耗 :15.9 MB, 在所有 python3 提交中击败了25.29%的用户
```
