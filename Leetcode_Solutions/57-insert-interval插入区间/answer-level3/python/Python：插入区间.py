### 解题思路
调的最久的一个，第一个100%，强行优化暴力算法
信号值+流程树
不存在特例
空间复杂度O(n)
时间复杂度O(n)
执行用时 :48 ms, 在所有 Python3 提交中击败了88.14%的用户
内存消耗 :15.2 MB, 在所有 Python3 提交中击败了100.00%的用户
继续优化思路：
二分，提高定位速度


### 代码

```python3
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        merged=[]
        signal=1
        for i in range(len(intervals)):
            if intervals[i][1] < newInterval[0]:
                merged.append(intervals[i])
            elif intervals[i][0] > newInterval[1]:
                if signal==2:
                    merged[-1][1]=max(newInterval[1],intervals[i-1][1])
                    merged.append(intervals[i])
                    signal=3
                elif signal==3:
                    merged.append(intervals[i])
                else:
                    merged.append(newInterval)
                    merged.append(intervals[i])
                    signal=3
            elif intervals[i][0] <= newInterval[0] and intervals[i][1] >= newInterval[1]:
                merged.append(intervals[i])
                signal=3
            else:
                if signal==1:
                    merged.append([min(newInterval[0],intervals[i][0]),0])
                    signal=2
                else:
                    continue
        if signal==1:merged.append(newInterval)
        if signal==2:merged[-1][1]=max(newInterval[1],intervals[-1][1])
        return merged
```