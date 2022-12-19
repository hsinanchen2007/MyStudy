### 解题思路

dp[i][j]表示 s1串前面i个字符与s2串前面j个字符与s3串前面i+j个字符相匹配
dp[i][j] 由 dp[i-1][j] 或 dp[i][j-1]递推获得

递推式子: dp[i][j] =  (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s3[i+j] == s2[j]) 

举例说明:
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
对上面例子来说: 
dp[1][0] = True
dp[1][1] = False #因为ad无论组合都不能与aa相匹配
dp[2][0] = True
dp[2][1] = False
dp[2][2] = (dp[2][1] && s2[0] == s3[2] ) or (dp[1][1] && s1[1] == s3[2]) 
注：初始边界需注意一下
### 代码

```python3
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str):
        l1,l2,l3 = len(s1),len(s2),len(s3)
        flag = False
        if l1 + l2 != l3:
                return False
        if l1 == 0 or l2 == 0:
            if s1 == s3 or s2 == s3:
                return True
            return False
        dp = [[False]*(l2+1) for _ in range(l1+1)]
        dp[0][0] = True
        '''
            dp[i][j]表示 s1串前面i个字符与s2串前面j个字符与s3串前面i+j个字符相匹配
            递推式子:
            dp[i][j] =  (dp[i-1][j] && if s3[i+j] == s1[i]) || (dp[i][j-1] && if s3[i+j] == s2[j]) 
        '''
        # 初始化
        for i in range(1,l1+1):
            if s1[i-1] == s3[i-1]:
                dp[i][0] = True
            else:
                break
        for i in range(1,l2+1):
            if s2[i-1] == s3[i-1]:
                dp[0][i] = True
            else:
                break

        for i in range(1,l1+1):
            for j in range(1,l2+1):
                dp[i][j] = (dp[i-1][j] and s3[i+j-1] == s1[i-1]) or (dp[i][j-1] and s3[i+j-1] == s2[j-1])
        return dp[l1][l2]
```