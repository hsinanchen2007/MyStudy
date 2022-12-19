这道题可以使用动态规划求解，dp[i]代表子数组A:i按要求操作能得到的最大和，状态转移方程为：dp[i]=max(dp[j]+max(A[j:i])*(i-j))(i-K <= j < i)，其中j表示最后一个分割数组的起始下标，max(A[j:i])表示子数组A[j:i]的最大值，i-K <= j < i保证分割的数组长度不大于K。  
```Python
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        dp = [0] * (n+1)
        for i in range(1,n+1):
            j = i - 1
            mx = -float('inf')
            while i - j <= K and j >= 0:
                mx = max(mx,A[j])
                dp[i] = max(dp[i],dp[j]+mx * (i - j))
                j -= 1
        return dp[n]
```