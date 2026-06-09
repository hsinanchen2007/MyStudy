### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        # 字符串开头第1个元素为0的话,个数为0
        if s[0] == "0":
            return 0
        n = len(s)
        dp = [0]*(n+1)
        dp[0],dp[1] = 1,1
        for i in range(2,n+1):
            if s[i-1] == "0":
                # 此情况下无法进行解码
                if int(s[i-2]) >= 3 or s[i-2] == "0":
                    dp[i] = 0
                # 此时,后面两位形成一个字母,总数等于前任
                elif s[i-2] == "2" or s[i-2] == "1":
                    dp[i] = dp[i-2]
            elif int(s[i-1]) <= 6:
                if int(s[i-2]) >= 3 or s[i-2] == "0":
                    dp[i] = dp[i-1]
                elif s[i-2] == "1" or s[i-2] == "2":
                    dp[i] = dp[i-1] + dp[i-2]
            elif int(s[i-1]) >= 7:
                if s[i-2] == "1":
                    dp[i] = dp[i-1]+dp[i-2]
                else:
                    dp[i] = dp[i-1]
        return dp[n]

```