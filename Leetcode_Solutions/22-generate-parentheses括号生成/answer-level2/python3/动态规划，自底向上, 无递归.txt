官方的方法感觉好复杂，来个简单的


```
class Solution:
    def generateK(self, dp, k):
        result = set()
        for i in range(1, k):
            if 2*i > k: break

            for s in dp[i]:
                for t in dp[k-i]:
                    if i == 1:
                        result.add( '(' + t + ')' )
                    result.add(s+t)
                    result.add(t+s)

        return list(result)

    def generateParenthesis(self, n: int) -> List[str]:
        dp = {}   # dp[i], i个'()'组成的全部组合
        dp[0] = []
        dp[1] = ['()']

        if n <= 0: return []

        for k in range(2, n+1):
            dp[k] = self.generateK(dp, k)

        return dp[n]

```
