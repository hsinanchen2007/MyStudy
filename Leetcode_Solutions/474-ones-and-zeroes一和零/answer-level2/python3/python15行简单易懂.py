### 解题思路 物品从少到多，指标从大到小 好好体会一下
1. 一个一个物品加
1. 大的要用到**上一轮**的小的，因此从大到小，确保上一轮的解不在用到时被本轮解覆盖掉，keke

### 代码

```python
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        ans,N = 0,len(strs)
        count,dp=[[0]*2 for _ in range(N)],[[0]*(n+1) for _ in range(m+1)]
        for i,str1 in enumerate(strs):
            count[i][0] = str1.count("0")
            count[i][1] = str1.count("1")
        for k in range(N):
            for i in range(m,-1,-1):
                for j in range(n,-1,-1):
                    if count[k][0] <=i and count[k][1] <=j:
                            dp[i][j] = max(dp[i-count[k][0]][j-count[k][1]]+1,dp[i][j])
                    ans = max(ans,dp[i][j])
        return ans

```