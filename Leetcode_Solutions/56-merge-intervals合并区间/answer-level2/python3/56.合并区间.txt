### 解题思路
- 区间[left,right],按照left升序排列
- 区间合并：将第一个区间写进ans,从第二区间开始检查是否能够与ans[-1]合并
- 若能则更新ans[-1]的right为两个区间中right的大值
- 若不能则将区间加入结果中,ans[-1]更新（每次都是检查结果队列的最后一个元素）

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []

        intervals.sort()
        ans = [intervals[0]]
        for i in range(1, len(intervals)):
            if ans[-1][1] >= intervals[i][0]:
                ans[-1] = [ans[-1][0], max(ans[-1][1], intervals[i][1])]
            else:
                ans.append(intervals[i])
        return ans


```