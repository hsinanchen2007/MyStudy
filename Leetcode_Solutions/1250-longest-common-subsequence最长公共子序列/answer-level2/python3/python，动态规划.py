### 解题思路
我们用一个二维数组dp[i][j]记录第一个字符串i的位置到第二个字符串j的位置之前最大相同字串的长度。
转移方程dp[i][j]=dp[i-1][j-1]+1,当text1[i-1]=text2[j-1]的时候
dp[i[j]=max(dp[i-1][j],dp[i][j-1])，当text1[i-1]！=text2[j-1]

### 代码
```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1=len(text1)
        len2=len(text2)
        dp=[[0] * (len2+1) for _ in range(len1+1)]
        for i in range(1,len1+1):
            for j in range(1,len2+1):
                if text1[i-1]==text2[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        return dp[len1][len2]
```

