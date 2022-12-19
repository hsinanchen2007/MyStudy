# 动态规划法
```
def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s
        if s == s[::-1]:
            return s
        
        lpdc = ""
        length = len(s)
        
        for i in range(length):
            for j in range(length-i):
                strTmp = s[i:i+1+j]
                if strTmp[-1] == strTmp[0]:
                    length_strTmp = len(strTmp)
                    half_len = length_strTmp // 2 + 1
                    if strTmp[:half_len] == strTmp[-half_len:][::-1]:
                        lpdc = strTmp if length_strTmp>len(lpdc) else lpdc
                        
        return lpdc
```
空间复杂度O(N), 时间复杂度O(N*N)
实际上可以不提前判断s长度小于2返回s，减少圈复杂度，但需判断重复字符否则超时。


