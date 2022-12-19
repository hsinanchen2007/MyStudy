### 解题思路


### 代码

```python
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 1
        length = len(s)
        dp =[[False]*length for _ in range(length)]
        dp[0][0] = True
        res = 0
        for j in range(0,length):
            for i in range(0,j+1):
                # if s[i] == s[j]:
                #     if j-i < 3:
                #         dp[i][j] = True
                #     else:
                #         dp[i][j] = dp[i+1][j-1]
                # else:
                #     dp[i][j] = False
                # if dp[i][j]:
                #     res += 1
                if (s[i] == s[j] and ((j-i<=2) or dp[i+1][j-1])):
                    dp[i][j] = True

                    res += 1

        return res 
                    
```