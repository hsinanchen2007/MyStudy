```
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        l_dp = [0] * (len(A) - L + 1)
        r_dp = [0] * (len(A) - L + 1)
        l = 0
        for i in range(0,len(A) - L + 1):
            l = max(sum(A[i:i+L]),l) 
            l_dp[i] = l
        r = 0
        for i in range(len(A) - L,-1,-1):
            r = max(sum(A[i:i+L]),r)
            r_dp[i] = r
        ans = 0
        for i in range(len(A) - M + 1):
            m_sum = sum(A[i:i+M])
            if i - L>=0: l_a_sum = l_dp[i - L]
            else: l_a_sum = 0
            if len(A) - (i+M)>=L: r_a_sum = r_dp[i+M]
            else: r_a_sum = 0
            ans = max(ans,m_sum+l_a_sum,m_sum+r_a_sum)
        return ans
```
