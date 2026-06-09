### 解题思路
    二维背包问题，dp[i][target][cost]表示前i项任务，可以满足target收益且人数小于cost的组合数量。
    转移方程：
        考虑第i项任务，有两种情况
        1）采取该项任务则，
            dp[i][target][cost] = dp[i-1][target-profit[i]][cost-group[i]]
        2）不采取该项任务，则
            dp[i][target][cost] = dp[i-1][target][cost]
        此时可以发现，第i项任务状态仅与第i-1项任务状态有关，且式（2）中为原地更新，因此可以将三维降至二维，合并两项：
            dp[target][cost] += dp[target-profit[i]][cost-group[i]]
        注意：profit，group均为正数，更新时将使用到dp表中上部数据，因此必须采用自底向上的顺序才能原地更新
    初始化：
        dp表格维度[P+1,G+1]
        将维度dp[0:]设置为1，代表当前target <= 0, 任务完成，计数 +1
    具体细节见代码备注

### 代码

```python3
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        # 初始化dp表，表第0行初始化为1
        dp = [[1] * (G+1)] + [[0] * (G+1) for _ in range(P)]
        n = len(group)
        # 全任务遍历
        for i in range(n):
            # 针对每项任务，全局更新每种target，cost组合
            # 自底向上，采用原地更新
            for target in reversed(range(P+1)):
                # 由于cost不能小于0，意味着超员，所以cost>=group[i]
                for cost in reversed(range(group[i], G+1)):
                    # profit可以小于0，意味着超额收益，将所有超额都归结至profit=0
                    dp[target][cost] += dp[max(0,target-profit[i])][cost-group[i]]
        return int(dp[-1][-1]%1000000007)
```
```