#### 思路
将`intervals`排序，判断每个区间结束点和下一个区间开始点的相互位置。
#### 代码
```
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()
        for i in range(len(intervals)-1):
            if intervals[i][1] > intervals[i+1][0]:
                return False
        return True
```
#### 复杂度分析
- 时间复杂度：O(NlogN)，N为数组长度，排序+遍历了一次数组
- 空间复杂度：O(1)

![白色背景关注.jpg](https://pic.leetcode-cn.com/6c18bb76abad971a2db54a010561f44fd1445ca10f9b671ecfee1a7df2482c08-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
