字符串本身和字符串反转之后的最长公共子串 就是删除最少字符可以得到的回文串
最后判断回文串长度是不是大于字符串长度减k

```
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        s1, l = s[::-1], len(s)
        res = ""
        
        rec = [[0]*(l+1) for _ in range(l+1)]
        
        for i in range(1, l+1):
            for j in range(1, l+1):
                
                if s[i-1]==s1[j-1]:
                    rec[i][j] = rec[i-1][j-1]+1
                    res = res+s[i-1]
                else:
                    rec[i][j] = max(rec[i][j-1], rec[i-1][j])
                 
        
        return rec[-1][-1]+k>=l
```
