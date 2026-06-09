### 解题思路
首先该题已经是无重合的有序区间，所以首先明确插入的数组只可能与前一个元素重合；因为插入区间的后一个值无法确定大小，所以后面的区间皆有重合可能
1、找到新区间的插入位置，从左到右比较左区间值即可
2、插入新元素，与前一个元素作比较
3、循环，与新元素之后的元素比较
4、若有重合，更新插入的新区间范围，并将重合的旧元素替换成一个不可能的区间，例如[0,-1]
5、最后删除[0,-1]即可

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        if n==0:
            intervals.append(newInterval)
            return intervals
        #find the position to insert
        idx = 0
        for i in range(n):
            if newInterval[0] > intervals[i][0]:
                idx += 1
                continue
            else:
                intervals.insert(i,newInterval)
                idx = i
                break
        #排到最后的特殊情况
        if idx == n:
            intervals.append(newInterval)
        #determine whether to merge, merge before and behind
            #往前比较只有前一个区间有可能合并
            if intervals[idx][1] <= intervals[idx-1][1]:
                intervals[idx] = intervals[idx-1]
                intervals[idx-1] = [0,-1]
            elif intervals[idx][0] <= intervals[idx-1][1]:
                intervals[idx][0] = intervals[idx-1][0]
                intervals[idx-1] = [0,-1]
        elif idx == 0:
            for k in range(idx+1,n+1):
                if intervals[idx][1] >= intervals[k][1]:
                    intervals[k] = [0,-1]
                elif intervals[idx][1]>=intervals[k][0]:
                    intervals[idx][1] = intervals[k][1]
                    intervals[k] = [0,-1]
                else:
                    break
        else:
            #往前比较只有前一个区间有可能合并
            if intervals[idx][1] <= intervals[idx-1][1]:
                intervals[idx] = intervals[idx-1]
                intervals[idx-1] = [0,-1]
            elif intervals[idx][0] <= intervals[idx-1][1]:
                intervals[idx][0] = intervals[idx-1][0]
                intervals[idx-1] = [0,-1]
            
            for k in range(idx+1,n+1):
                if intervals[idx][1] >= intervals[k][1]:
                    intervals[k] = [0,-1]
                elif intervals[idx][1]>=intervals[k][0]:
                    intervals[idx][1] = intervals[k][1]
                    intervals[k] = [0,-1]
                else:
                    break
        #删除元素
        for l in range(n,-1,-1):
            if intervals[l] == [0,-1]:
                intervals.pop(l)
        return intervals
```