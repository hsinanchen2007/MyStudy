```
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        """
           首先按照第一个坐标排序,
           第一个坐标相等的条件下按照第二个坐标排序

           使用双指针, 一遍遍历 
           假设有慢快指针i和j, 如果此时i无法覆盖此时的j, 那么直接将j赋值给i, 然后j加1, 

           那么问题肯定是为什么不接着将i与j以后的元素一个一个比较, 观察是否能否覆盖呢？

           假如 i可以覆盖j+1, 那么很显然j必然也可以覆盖j+1. 因为前面如果i不能覆盖j, 
           说明i < j, 所以可以得到j必然也能覆盖j+1位置的元素
        """
        size = len(intervals)
        if size < 2:
            return size
        sorted_intervals = sorted(intervals, key=lambda x: (x[0],x[1]))

        i, j = 0, 1
        count = 0
        while i < size and j < size:
            if sorted_intervals[i][1] >= sorted_intervals[j][1]:
                count += 1
                j += 1
            elif sorted_intervals[i][1] < sorted_intervals[j][1]:
                i = j
                j += 1
        
        return (size - count)
```
