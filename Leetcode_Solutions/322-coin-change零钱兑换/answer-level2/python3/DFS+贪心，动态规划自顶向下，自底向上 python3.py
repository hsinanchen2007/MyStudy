
### DFS+贪心
DFS的解释详见【零钱兑换】贪心 + dfs = 8ms
```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        self.ans = float('inf')
        coins.sort(reverse=True)
        ans = self.dfs(coins,0,amount,0)
        return self.ans if self.ans != float('inf') else -1

    def dfs(self,coins,c_index,amount,cnt):
        if amount == 0:
            self.ans = min(self.ans,cnt)
            return
        elif c_index == len(coins):
            return
        k = amount//coins[c_index] # 乘法优化
        while k >= 0 and k + cnt < self.ans: # k + cnt < self.ans 剪枝
            self.dfs(coins,c_index+1,amount-k*coins[c_index],cnt+k)
            k -= 1
```

### 动态规划，自底向上，最自然
动态规划的解释详见 Java 递归、记忆化搜索、动态规划

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 备忘录
        #   存储 memo[amount] = 最少兑换硬币数量（的和等于amount）
        #   memo[0] = 0 兑换钱币0，需要0个硬币
        memo = [0]*(amount+1) 
        # 从下到上
        for cur_amount in range(1,amount+1):
            ans = float('inf')
            for coin in coins:
                if cur_amount - coin >= 0 and memo[cur_amount - coin] < ans:
                    ans = memo[cur_amount - coin] + 1
            memo[cur_amount] = ans
        return memo[amount] if memo[amount] != float('inf') else -1
    

        
```
### 动态规划，自顶向下,递归
动态规划的解释详见 Java 递归、记忆化搜索、动态规划
```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 备忘录
        #   存储 memo[amount] = 最少兑换硬币数量（的和等于amount）
        #   memo[0] = 0 兑换钱币0，需要0个硬币
        self.memo = [0]*(amount+1) 

        self.findWay(coins,amount)
        return self.memo[amount]

    def findWay(self,coins,amount):
        if amount < 0:
            return -1
        if amount == 0:
            return 0
        # 在备忘录里查找
        #   精髓，11 -1 -2 = 11 -2 -1 = 8 都是2个硬币，在这里就会避免递归重复的
        if self.memo[amount] != 0:
            return self.memo[amount]

        ans = float('inf')
        # 递归 1,2,5
        for i in range(len(coins)):
            res = self.findWay(coins,amount-coins[i])
            if res >= 0 and res < ans:
                ans = res + 1
        self.memo[amount] = ans if ans != float('inf') else -1
        return self.memo[amount]
```
