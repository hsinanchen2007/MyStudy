### 解题思路
题目本质是靠斐波那契数列，理解这个本题就解出来了：
n== return 1 ## 1-1 型Fib问题
n==1 return 1
dp=dp[i-1]+dp[i-2]

利用列表进行结果存储dp=[],记得取模

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        if n==0:
            return 1
        if n==1:
            return 1
        dp=[1,1]
        for i in range(2,n+1):
            dp.append((dp[i-1]+dp[i-2])%1_000_000_007)
        return dp[-1]
```