### 解题思路
就是跳台阶，但是需要判断很多条件
对0的处理比较麻烦

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        dp=[0]*(len(s)+1)
        dp[0]=1
        dp[1]=1 if s[0]!="0" else 0
        for i in range(2,len(s)+1):
            if 1<=int(s[i-2:i])<=26:
                if s[i-1]!="0" and s[i-2]!="0":
                    dp[i]=dp[i-1]+dp[i-2]
                elif s[i-1]=="0" and s[i-2]!='0':
                    dp[i]=dp[i-2]
                else:
                    dp[i]=dp[i-1]
            else:
                if s[i-1]=="0":
                    return 0
                dp[i]=dp[i-1]    
        return dp[-1]
                





        
```