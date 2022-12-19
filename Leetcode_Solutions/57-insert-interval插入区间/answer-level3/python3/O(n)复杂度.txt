### 解题思路
根据题目描述，给定的区间集合中各个子区间是不相交的，且区间开端已经排好序。
那么该题的可以想找到newInterval 的插入位置，然后再进行合并区间即可

### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        cnt = len(intervals)
        rst = []
        idx = 0

        #找到插入位置
        while idx<cnt and intervals[idx][0]<newInterval[0]:
            idx += 1
        intervals.insert(idx, newInterval)

        # 循环拷贝，且在拷贝的过程中检测可以合并的区间
        rst = [intervals[0]]
        for i in range(1, len(intervals)):
            # 如果可以和结果集的最后一个区间有交集则合并，并且更新
            if intervals[i][0] <= rst[-1][1]:
                rst[-1][1] = max(rst[-1][1], intervals[i][1])
            # 如果和结果集的最后一个区间没有交集，则直接加入到结果集中
            else:
                rst.append(intervals[i])
        return rst

        


            
```