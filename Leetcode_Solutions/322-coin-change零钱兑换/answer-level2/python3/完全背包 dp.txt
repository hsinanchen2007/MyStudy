### 解题思路
和279基本类似
dp[i]定义能达到总金额为i时的最小硬币个数
# 这和上一题一样, 这里是给价值求个数!
# 传统背包九讲里, 是求价值! 所以dp[i]的设计方式不一样, 意义也不一样

### 代码

dp能beat 50
```python3
# 这和上一题一样, 这里是给价值求个数!
        # 传统背包九讲里, 是求价值! 所以dp[i]的设计方式不一样, 意义也不一样
        # lc = len(coins)
        # dp = [float('inf')]*(amount+1)
        # dp[0] = 0
        # # coins_set = set(coins)
        # for i in range(1, amount+1):
        #     for j in range(lc):
        #         if i>=coins[j]:
        #             dp[i] = min(dp[i], dp[i-coins[j]]+1) 
        # return dp[-1] if dp[-1]!=float('inf') else -1
```
memo递归和bfs思路的都只能beat 5

```
    def solve(i, n):
            if i<0:
                return float('inf')
           if n==0:
                return 0
            key = '%d %d' % (i, n)
            if key in memo:
                return memo[key]
            elif coins[i]>n:
                memo[key] = solve(i-1, n)
            else:
                A = solve(i, n-coins[i])+1
                B = solve(i-1, n-coins[i])+1
                C = solve(i-1, n)
                memo[key] = min(A, B, C)
            return memo[key]
        memo = {}
        res = solve(len(coins)-1, amount)
        return res if res!=float('inf') else -1
```
BFS, visited很重要不然会超时
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        q = []
        l, rest = len(coins)-1, amount
        q.append((amount, 0)) # 剩余金额, 当前个数
        visited = set()
        # coins = sorted(coins) 不需要排序 反而会耗时
        while q:
            cur = q.pop(0)
            if cur[0]==0:
                return cur[1]
            if cur[0] not in visited:
                visited.add(cur[0])
            else: continue
            for c in coins:
                if c<=cur[0]:
                    q.append((cur[0]-c, cur[1]+1))
        return -1
```
大佬的dfs, 只需要50ms 
主要就是想办法去剪枝

```
import math
class Solution:
    def coinChange(self, coins, amount: int) -> int:
        n = len(coins)
        coins = sorted(coins, reverse=True) # 由大到小
        res = amount + 1

        def dfs(index, target, count):
            nonlocal res
            this_coin = coins[index] # 当前的coin一定是比之后要遍历的coin大, 这个很关键
            if count + math.ceil(target / this_coin) >= res: #即便之后全部使用当前最大金额所用硬币个数的仍比res多 就不用向后遍历了
                return

            if target % this_coin == 0: 
                res = count + target // this_coin

            if index == n - 1: ## 已经遍历到最后一个了
                return

            for i in range(target // this_coin, -1, -1): # 每次都尽可能减去更多的金额 
                dfs(index + 1, target - i * this_coin, count + i)

        dfs(0, amount, 0)

```
