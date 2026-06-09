### 解题思路
执行用时 :84 ms, 在所有 Python3 提交中击败了10.71%的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了50.00%的用户

### 代码
```python3
class Solution:
    def numberOfWays(self, num_people: int) -> int:
        mod = 10**9 + 7
        dp = [0] * (num_people+1)
        dp[0] = 1
        dp[2] = 1
        for n in range(4, num_people+1, 2):
            for m in range(0, n//2):
                j = 2*m + 1
                dp[n] += dp[j - 1]*dp[n-j-1]

        return int(dp[num_people] % mod)
        
```