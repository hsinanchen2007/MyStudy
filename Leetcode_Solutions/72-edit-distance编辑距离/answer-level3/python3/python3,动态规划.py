```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp=[[0]*(len(word2)+1) for _ in range(len(word1)+1)]
        #dp[i][j]表示words1的前i个字符转换到words2的前j个字符需要的最小操作数

        for i in range(1,len(word1)+1):
            dp[i][0]=dp[i-1][0]+1
        for i in range(1,len(word2)+1):
            dp[0][i]=dp[0][i-1]+1
        #注意需要初始化第0行和第0列，相当于只添加或者只删除的操作
        #dp[i-1][j]--->dp[i][j]相当于删除操作，删除words1[i]字符
        #dp[i][j-1]--->dp[i][j]相当于添加操作，在words1中添加words2[j]字符
        #dp[i-1][j-1]--->dp[i][j]想相当于替换操作，words1[i]替换为words2[j]字符
        for i in range(1,len(word1)+1):
            for j in range(1,len(word2)+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
        return dp[-1][-1]
```
