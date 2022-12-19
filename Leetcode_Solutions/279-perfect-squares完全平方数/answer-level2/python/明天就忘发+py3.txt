### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        # 每个数字最多的数量数 比如都是1  然后 3=3
        # dp[i]表示i元素 完全平方数最少的数量
        dp=list(range(n+2))

        squarList=[i*i for i in range(int(n**0.5)+1)]

        for i in range(n+1):
            for num in squarList:
                if i<num:
                    break
                #相当于 dp[5]=dp[4]+dp[1]
                dp[i]=min(dp[i],dp[i-num]+1)
        return dp[n]
```