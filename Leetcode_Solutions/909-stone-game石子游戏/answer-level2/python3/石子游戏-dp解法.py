原以为很难，后来想到是属于dp的知识就很简单了.
思路：dp[i][j]记录区间[i,j]内先出手者的最大得分
```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n =len(piles)
        a = [[0]*n for i in range(n)]
        def dp(i,j):
            if i==j:
                return piles[i]
            if a[i][j]>0:
                return a[i][j]
            a[i][j] = max(piles[i]+dp(i+1,j),piles[j]+dp(i,j-1))
            return a[i][j]
        return 2*dp(0,n-1)>sum(piles)

```
