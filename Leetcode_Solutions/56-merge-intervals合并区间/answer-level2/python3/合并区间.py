### 递推式
f(n+1) = f(n) 的栈顶与 n+1 的合并结果
### 边界条件
1. 为空时候的返回
2. 两个区间紧邻时候是否合并
3. 栈要先退再进
4. 应该先自己检查正确性再提交。这倒不是说工作会这样，而是应当有这种能力。
### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals = sorted(intervals, key=(lambda x : x[0]))
        ans = []
        ans.append(intervals[0])
        for i in range(1, len(intervals)):
            if intervals[i][0] <= ans[-1][1]:
                temp = ans[-1]
                ans.pop()
                ans.append(list((temp[0], max(temp[1], intervals[i][1]))))
            else:
                ans.append(intervals[i])
        return ans
```