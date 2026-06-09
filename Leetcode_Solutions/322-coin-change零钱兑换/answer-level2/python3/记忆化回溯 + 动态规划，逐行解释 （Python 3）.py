
## 记忆化回溯（自顶向下）

![image.png](https://pic.leetcode-cn.com/913498f362d6febe8b50fb6b115a1ed300a98f99277d8a9891fd166377d99c50-image.png){:width=350}

如上图，在回溯过程中，将中间结果保存下来，这样可将复杂度降低到 $O(n)$。

 1. 初始化记忆词典 $memo=\{0:0\}$，表示 $0$ 元的组成种类为 $0$，保存出现过的面值。
 2. 定义回溯函数 $helper(n)$，$n$ 表示当前的面值：
 	+ 若面值已经计算过，即面值出现在 $memo$ 中，返回 $memo[n]$。
 	+ 设置最小组成数 $res=MAX$。
 	+ 遍历每种面额的硬币 $coin$：
 		+ 必须满足条件 $n>=coin$，表示金额必须比硬币面值大。此时 $res=min(res,helper(n-coin)+1)$，始终更新为最小组成数。
 	+ 将结果保存到 $memo$ 中。
 	+ 返回 $res$
 
 3. 若 $helper(amount)$ 不为 $MAX$，则返回，否则返回 $-1$
  
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

```python [-Python 3]
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo={0:0}
        def helper(n):   
            if(n in memo):
                return memo[n]
            res=float("inf")
            for coin in coins:
                if(n>=coin):
                    res=min(res,helper(n-coin)+1)
            memo[n]=res
            return res
        return helper(amount) if(helper(amount)!=float("inf")) else -1
```


## 动态规划（自下而上）
$dp[i]$ 保存金额 $i$ 的最小组成数。

 1. 初试化 $dp=[MAX,\cdots,MAX]$，长度为 $amount+1$
 2. $dp[0]=0$，表示 $0$ 元的组成种类为 $0$
 3. 遍历 $dp$ 数组，$i$ 遍历区间 $[1,amount+1)$：
 	+ 遍历每种硬币的面值 $coin$：
 		+ 必须满足条件 $i>=coin$，表示金额必须比硬币面值大。$dp[i]=min(dp[i],dp(i-coin)+1)$，保证保存的是最小的组成数。
 
 4. 若 $dp[amount]$不为$MAX$，则返回，否则返回 $-1$。

### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

```python [-Python 3]
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        dp=[float("inf")]*(amount+1)
        dp[0]=0
        for i in range(1,amount+1):
            for coin in coins:
                if(i>=coin):
                    dp[i]=min(dp[i],dp[i-coin]+1)
        return dp[-1] if(dp[-1]!=float("inf")) else -1
```

