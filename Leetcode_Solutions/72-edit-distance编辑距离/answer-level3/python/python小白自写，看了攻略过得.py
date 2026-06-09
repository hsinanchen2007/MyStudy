### 解题思路
小白学习动态规划也是看了不少解析过来的，然后再过来解这题，还是没有头绪，但是简要整理一下思路，供后人和自己以后参考，动态规划很重要的一点是将其转化为数组之间的关系。一开始看到这题，完全没有想到dp[i-1][j-1]是什么意思，但是联想一下就可以得知状态的转换正好可以从题意过来，多多思考，天天向上。
### 代码

```python
class Solution(object):
    def minDistance(self, word1, word2):
        n1=len(word1)
        n2=len(word2)
        #init
        dp=[[0]*(n2+1) for _ in range(n1+1)]
        for i in range(n1+1):
            dp[i][0]=i
        for j in range(n2+1):
            dp[0][j]=j
        #dpcompute
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                up=dp[i-1][j]
                left=dp[i][j-1]
                pre=dp[i-1][j-1]
                if word1[i-1]==word2[j-1]:

                    dp[i][j]=min(up+1,left+1,pre)
                else:
                    dp[i][j]=1+min(up,left,pre)
        return dp[-1][-1]
```