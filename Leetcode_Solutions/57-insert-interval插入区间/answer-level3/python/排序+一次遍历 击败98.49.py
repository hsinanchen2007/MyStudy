### 解题思路
此处撰写解题思路
1.扩充插入集合
2.排序，按照集合的第一元素大小排序
3.遍历，判断每一个区间最小和最大的边界
### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()
        l=len(intervals)
        res=[]
        if l ==0:
            return res
        i=1
        min_num=intervals[0][0]
        max_num=intervals[0][1]
        while i<l:
            if max_num>=intervals[i][0] and max_num>=intervals[i][1]:
                pass
            elif max_num>=intervals[i][0] and max_num<intervals[i][1]:
                max_num=intervals[i][1]
            else:
                res.append([min_num,max_num])
                min_num=intervals[i][0]
                max_num=intervals[i][1]
            i+=1
        res.append([min_num,max_num])
        return res
```