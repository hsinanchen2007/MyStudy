### 解题思路
之前看到的全部没考虑重复数字的问题，都不知道写答案的人到底有没有自己运行过。。。无语

### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:

        dp = [1] * (n)
        a, b, c  = 0, 0, 0
        i = 1
        while i < n:
            n2, n3, n5 = dp[a] * 2, dp[b] * 3, dp[c] * 5
            dp[i] = min(n2,n3,n5)
            if dp[i] == n2:
                a += 1
            elif dp[i] == n3:
                b += 1
            else:
                c += 1
            if dp[i] == dp[i-1]:
                i = i - 1
            i = i + 1
        return dp[-1]

```