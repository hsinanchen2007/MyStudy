### 解题思路
if arr[i]==arr[j]: dp[i][j]=dp[i+1][j-1]
else: dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j])

### 代码

```python3
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        # dp[i][j]删除arr[i:j+1]这一段所需要进行的操作次数
        # if arr[i]==arr[j]: dp[i][j]=dp[i+1][j-1]
        # else: dp[i][j]=min(dp[i][k]+dp[k+1][j])
        dp=[[float("inf") for _ in range(len(arr))] for _ in range(len(arr))]                
        for j in range(len(arr)):
            for i in range(j,-1,-1):
                if i==j:
                    dp[i][j]=1
                elif i+1==j and arr[i]==arr[j]:
                    dp[i][j]=1
                elif i+1==j and arr[i]!=arr[j]:
                    dp[i][j]=2
                else:
                    if arr[i]==arr[j]:
                        dp[i][j] = dp[i + 1][j - 1]
                    else:
                        for k in range(i, j):
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j])
        return dp[0][-1]
```