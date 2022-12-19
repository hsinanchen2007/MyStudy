### 解题思路
空间击败100%,O(1)
时间，O(N)
![image.png](https://pic.leetcode-cn.com/bd33bc8f5c7cfbb43e3ec8d8647ee256cc64ea8adc15d64efd97e8c8d051d1bc-image.png)
我们通过题目容易得到，每个列表区间只能和插入区间有两种关系，合并和不合并，所以我们可以将插入区间放到列表头部，遍历列表，通过判断相互条件，将列表区间变为新的插入区间。
下面具体说每一种情况
我们由题目，容易确定插入区间和给定列表内的区间相互条件只有以下几种：
一。合并
1.插入区间在列表区间的内部，这时候就合并，pop出插入区间，而**这个列表区间就成为新的插入区间**
2.列表区间在插入区间内部，同1
3.列表区间最大值在插入区间内部，这时这个列表区间的最大值改成插入区间的最大值，并且成为新的插入区间，pop出之前的插入区间
4.列表区间最小值在插入区间内部，同3
二。不合并
1.如果插入区间最小值大于列表区间最大值，交换他们的位置，继续遍历
2.如果插入区间最大值小于列表区间最小值，不用交换，继续遍历即可(这时候相当于这个列表区间成为了新的插入区间)，其实之后不用判断了。请大家自己分析


### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if [[] for i in range(len(intervals))]==intervals:return [newInterval]
        intervals = [newInterval]+intervals
        i=1
        j = len(intervals)-1
        while i<=j:
            if intervals[i-1][0] >=intervals[i][0] and intervals[i-1][1] <=intervals[i][1]:
                
                intervals.pop(i-1)
                i =i-1
                j = j-1

            elif intervals[i][1]<intervals[i-1][0]:
                intervals[i],intervals[i-1] = intervals[i-1],intervals[i]
            
            elif intervals[i][1]<=intervals[i-1][1] and intervals[i][0]>=intervals[i-1][0]:
                intervals[i] = intervals[i-1]
                intervals.pop(i-1)
                i =i-1
                j = j-1
            elif intervals[i][1] in [i for i in range(intervals[i-1][0],intervals[i-1][1]+1)]:
                intervals[i] = [intervals[i][0],intervals[i-1][1]]
                intervals.pop(i-1)
                i = i-1
                j= j-1     
            elif intervals[i][0]>intervals[i-1][1]:
                pass
            else:
                intervals[i] = [intervals[i-1][0],intervals[i][1]]
                intervals.pop(i-1)
                i =i-1
                j = j-1
            #print(intervals,i,j)
            i+=1
        return intervals
```