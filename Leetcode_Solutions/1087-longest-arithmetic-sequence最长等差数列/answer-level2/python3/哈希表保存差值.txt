### 解题思路
dp:暴力的遍历

### 代码

```python3
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        if not A:
            return 

        size=len(A)
        maxLen=1
        dp=[{} for _ in range(size)]

        for i in range(1, size):
            for j in range(i):
                temp=A[i]-A[j]
                if temp not in dp[j]:
                    dp[i][temp]=2
                else:
                    dp[i][temp]=dp[j][temp]+1
                maxLen=max(maxLen, dp[i][temp])
        return maxLen
```