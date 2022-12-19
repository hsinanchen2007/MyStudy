### 解题思路
- 先填坑：二维列表的如果这么初始化dp=[[False]*len(s)]*len(s),dp[3][3]=True会修改所有第三列！而不是元素[3][3]
- 解决方案：初始化dp=[[False]*len(s) for _ in range(len(s))]
- 思路：动态规划 dp[i][j]= (s[]==s[]) and (j-i<=2 or dp[i+1][j-1])
- 要点：为了保证判断dp[i][j]的时候，dp[i+1][j-1]已经判断过了
- i递减循环,初始化为len-2
- j递增循环,初始化为i   
- 复杂度O(N^2)

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)<=1:return s
        dp = [ [False]*len(s) for _ in range(len(s))]
        res = ''
        for i in range(len(s)-2,-1,-1):
            for j in range(i,len(s)):
                dp[i][j]= (s[i]==s[j]) and (j-i<=2 or dp[i+1][j-1])
                if dp[i][j] and (j-i+1)>=len(res):
                    res = s[i:j+1]
        return res
```