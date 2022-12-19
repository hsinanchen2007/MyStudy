动态规划。在开始计算之前，先把题目给出的数据整理一下。将 `[startTime[i], endTime[i], profit[i]]` 整理为数组，并按 `startTime[i] - endTime[i] - profit[i]]` 排序。

用 `dp[i]` 表示完成第 `i` 份工作所能获得的最大收益。假设有第 `x` 份工作（`x < i`）：

- 如果 `x` 与 `i` 时间上不重合，表示即可完成工作 `x` 又可以完成工作 `i`，那么有：`dp[i] = max(dp[i], dp[x] + profit[i])`
- 如果 `x` 与 `i` 在时间上重合了，那么将无法完成工作 `x`

由此可见，`dp[i]` 的值**取决于在它前面所有与之时间不重合的工作收益**，即：

```
dp[i] = max(dp[0], dp[1], ..., dp[j]) + profit[i] （`j` 为 `i` 之前最后一个与之时间区域不重合的工作）
```

但是，如果每次都遍历 `0 ~ j` 必然会超时，所以需要记录下时间区域不重合的工作所在的最大位置。

```python
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        length = len(startTime)
        times = [[0, 0, 0] for _ in range(length)]
        for i in range(length):
            times[i][0] = startTime[i]
            times[i][1] = endTime[i]
            times[i][2] = profit[i]
        times.sort() # 排序
                
        dp = [0 for i in range(length)]
        
        res = 0
        s = 0
        pos = 0 # 标记位置
        for i in range(length):
            for j in range(pos, i):
                # 区间不重合
                if times[i][0] >= times[j][1]:
                    # 移动 pos 的位置
                    if j == pos:
                        pos += 1
                    s = max(s, dp[j])
             
            dp[i] = s + times[i][2]
            res = max(res, dp[i])
                              
        return res
```