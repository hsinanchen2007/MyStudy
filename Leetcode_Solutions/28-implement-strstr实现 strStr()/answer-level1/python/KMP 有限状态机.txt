### 解题思路


### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle: return 0 
        elif not haystack: return -1
        len_hay, len_nee = len(haystack), len(needle)
        base = ord('a')
        def KMP(s): # 构造状态机
            dp = [[0]*26 for _ in range(len(s))]
            X = 0
            dp[0][ord(s[0])-base] = 1 
            for i in range(1, len(s)): #从1 开始
                for j in range(26):
                    dp[i][j] = dp[X][j]
                dp[i][ord(s[i])-base] = i+1
                X = dp[X][ord(s[i])-base]
            return dp
        
        dp = KMP(needle)
        cur = 0
        for i in range(len_hay):
            cur = dp[cur][ord(haystack[i])-base] # cur代表当前所处状态
            if cur==len_nee: return i-len_nee+1
        return -1
            

```