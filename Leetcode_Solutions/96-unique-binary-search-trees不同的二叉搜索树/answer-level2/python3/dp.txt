### 解题思路
dp[i] 代表1-i尾结点组成的二叉搜索树的种类

### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        dp=[0]*(n+1)        #初始值为0，不然后续累加出问题
        dp[0] = 1           #注意此处为1
        dp[1] = 1
        for i in range(2,len(dp)):
            for j in range(i):
                dp[i] += dp[j] * dp[i-1-j]  #G(n)=G(0)∗G(n−1)+G(1)∗(n−2)+...+G(n−1)∗G(0) 卡特兰数公式
        return dp[n]
```