### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        dp = [0]*(len(num)+5)
        dp[0]=1
        dp[1]=1
        for i in range(2,len(num)+1):
            if int(num[i-2]+num[i-1])<26 and num[i-2]!='0':dp[i] = dp[i-1]+dp[i-2]
            else:dp[i]=dp[i-1]
        return dp[len(num)]
```