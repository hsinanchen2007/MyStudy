### 解题思路
状态转移公式：
        #case1:1<=s[i-1:i]<=26 
        1:(1)
        12: (1,2);(12)
        121:(1,2,1);(12,1);(1,21)#在第二行的结果后面加1 + 在第一行的结果后面加21
        dp[i] = dp[i-1]+dp[i-2]
        
        #case2:s[i-1:i]不在范围内
        1:(1)
        12: (1,2);(12)
        129:(1,2,9);(12,9)在第二行的结果后面加1
        dp[i] = dp[i-1]
        
        #case3:考虑0的情况
        1:(1)
        12: (1,2);(12)
        120:(1,20)在第一行的结果后面加1
        dp[i] = dp[i-2]

        1:(1)
        13: (1,3);(13)
        130:NA
        dp[i] = 0

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0]=='0':
            return 0
        dp = [0 for _ in range(len(s)+1)]
        dp[0] = 1
        dp[1] = 1
        for i in range(1,len(s)):
            pre = s[i-1:i+1]
            if s[i] != '0':
                if int(pre)>=1 and int(pre)<=26 and s[i-1]!='0':
                    dp[i+1] = dp[i-1]+dp[i]
                else:
                    dp[i+1] = dp[i]
            else:

                if int(pre)>=1 and int(pre)<=26 and s[i-1]!='0':
                    dp[i+1] = dp[i-1]
                else:
                    dp[i+1] = 0
        return dp[-1]
```