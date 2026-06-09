### 解题思路
dp数组11*10，dp[i][j]：第i位为j的2的个数
状态转移方程：
if j≠2：dp[i][j] = dp[i-1][0~9]
else：dp[i][j] = dp[i-1][0~9] + 10**(i-1)
计算个数时从高数位向低数位遍历，并且需要特判当前位为2的情况，只需将结果加上低于当前位的数再加一（加一为0的情况）。
例如：n=5263，从千分位5向个位3遍历，当遇到百分位为2时，结果加上63+1，即200~263共64个百分位为2的数。


### 代码

```python3
class Solution:
    def numberOf2sInRange(self, n: int) -> int:
        tmp = n
        dp = [[0] * 10 for _ in range(11)]
        for i in range(1, 11):
            ss = 0
            for k in range(10):
                ss += dp[i - 1][k]
            for j in range(10):
                if j == 2:
                    dp[i][j] = ss + 10**(i - 1)
                else:
                    dp[i][j] = ss
        nums = [0]
        while n != 0:
            nums.append(n%10)
            n //= 10
        ans = 0
        for i in range(len(nums)-1,0,-1):
            if nums[i]==2:
                ans += tmp%(10**(i-1))+1
            for j in range(nums[i]):ans += dp[i][j]
        return ans
```