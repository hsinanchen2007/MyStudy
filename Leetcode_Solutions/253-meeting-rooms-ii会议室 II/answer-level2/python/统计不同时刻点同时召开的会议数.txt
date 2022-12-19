### 解题思路
> 很直观的想法是需要的最多的会议室个数，等于同时召开的会议数目；
- 1. 蛮办法：假设知道时刻点信息，每个区间左闭右开，比如 [1,3) 对区间内的时刻点进行逐一+1操作，依次对时刻点1,2进行+1的操作，最后统计出整个大区间里面的最大值； 遇到问题，区间不能太大， 中间空白太多遍历会浪费时间；
- 2. 优化的统计方法： 不用对区间内的每个时间点， 直接记录所有的变化时刻点， 如果是会议开始时间，则会议数目+1， 如果是会议结束时间则会议数目-1；会议室数目就是在变化时刻统计出来的最大值； 如果某时刻点有会议结束同时又会议创建，则先计算结束的后计算开始的即可；相比蛮力破解有很大提升；

### 代码

```python3
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        checkpoints = [(i[0], 1) for i in intervals]
        checkpoints += [(i[1], -1) for i in intervals]
        ans = 0
        curr = 0
        checkpoints.sort()
        for time, action in checkpoints:
            curr += action
            ans = max(ans, curr)
        return ans
```

# 运行情况
```
执行用时 :56 ms, 在所有 Python3 提交中击败了71.69%的用户
内存消耗 :16.4 MB, 在所有 Python3 提交中击败了9.09%的用户
```