### 解题思路
此处撰写解题思路
Dynamic Problem. dp[i][j]代表着在idx为i，差为j时最长的等差数列。注意1.用list中的dict代替list[list[]]去做变长度的DP。2.从前往后做。
### 代码

```python3
class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        dp = [{} for _ in range(len(A))]
        max_ans = 1
        for i in range(1,len(A)):
            for j in range(i):
                dp[i][A[i] - A[j]] = dp[j].get(A[i] - A[j],1) + 1
                max_ans = max(max_ans,dp[i][A[i] - A[j]])
        return max_ans
```