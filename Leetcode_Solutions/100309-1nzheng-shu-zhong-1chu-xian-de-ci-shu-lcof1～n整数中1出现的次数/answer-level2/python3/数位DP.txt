### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countDigitOne(self, n: int) -> int:
        dp = [[0]*10 for _ in range(10)]
        dp[0][1]=1
        for i in range(1,10):
            tmp = sum(dp[i-1])
            for j in range(10):
                if j==1:
                    dp[i][j] = tmp+10**i
                else:dp[i][j] = tmp
        ans = 0
        n = list(map(lambda x:int(x),list(str(n))))[::-1]
        num = 0
        for i in range(len(n)):
            ans += sum(dp[i][:n[i]])
            if n[i]==1:ans += num+1
            num += n[i]*(10**i)
        return ans
```