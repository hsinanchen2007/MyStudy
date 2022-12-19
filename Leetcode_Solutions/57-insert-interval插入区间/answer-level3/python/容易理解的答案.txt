参考：https://leetcode.com/problems/insert-interval/discuss/21602/Short-and-straight-forward-Java-solution

```python
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        index = 0
        # 处理inerval在newInterval之前的区间
        while index < len(intervals) and intervals[index][1] < newInterval[0]:
            result.append(intervals[index])
            index += 1
        
        # 处理interval和newIntercal有重叠的部分
        while index < len(intervals) and intervals[index][0] <= newInterval[1]:
            newInterval[0] = min(intervals[index][0], newInterval[0])
            newInterval[1] = max(intervals[index][1], newInterval[1])
            index += 1
        
        result.append(newInterval)

        # 剩余部分
        while index < len(intervals):
            result.append(intervals[index])
            index += 1

        return result
```
