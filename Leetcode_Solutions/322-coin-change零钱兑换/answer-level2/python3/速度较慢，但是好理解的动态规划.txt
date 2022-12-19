### 解题思路

整体思路：从 1 开始计算 dp


#### 计算的过程

我们要注意 2 点，
 
- 当 `dp[i] < 0` 时，这个数就是无效的
- 当 `i == coins[x]` 时，`dp[i] = 1`

```python
dp[i] = min(dp[i-coins[0]], ....., dp[i-coins[-1]]) + 1
# 特例
if i == coins[x]:
    dp[i] = 1
# 当 dp[i] < 0 时，这个数就无效了
```

### 代码

```python
class Solution:
    def coinChange(self, coins, amount: int) -> int:
        coins.sort()  # 排序 coin
        dp = [0 for _ in range(amount+1)]
        dp[0] = 0

        for i in range(1, amount+1):  # 从 1 开始计算 dp
            temp = []  # 用来存储针对 每个 coin 的当前 dp[i] 的可能值
            for j in coins:
                if i - j == 0:  # 特例 1：如果 i == coin： dp[i] = 1
                    temp.append(0)  # 这里使用了 0，因为我们把 1 都放在最后加了
                    break
                elif i - j < 0:  # 特例 2：如果 i < coin 了，我们也没必要遍历下面的coin了
                    break
                else:
                    if dp[i-j] >= 0:  # 只有 dp[i] >= 0 的值，才是有效的
                        temp.append(dp[i-j])
            if temp:
                dp[i] = min(temp) + 1  # 这里就是计算：min（temp） + 1，取上面所有 coin 计算过的最小值 + 1
            else:
                dp[i] = -1  # 当 temp 为空时，说明无法组成当前 i，将 dp[i] = -1 置为无效
        return dp[amount]  # 返回 dp[amount] 即可
```