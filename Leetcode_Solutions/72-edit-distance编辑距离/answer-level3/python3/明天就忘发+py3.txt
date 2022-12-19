### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # word1-->word2
        m=len(word1)
        n=len(word2)
        # 增加一行和一列 主要是当word1、word2可能为空“ ”
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            # 0，1，2，3，4，5...
            dp[i][0]=i
        for j in range(1,n+1):
            # 0
            # 1
            # ...
            dp[0][j]=j
        for i in range(1,m+1):
            for j in range(1,n+1):
                #从0标号
                if word1[i-1]==word2[j-1]:
                    # 字符相等 i，j 两个指针都向前移动，
                    # 转变为求dp[0-i-1][0-j-1]
                    dp[i][j]=dp[i-1][j-1]
                else:
                    # 不相等 则选择最小的三个操作 增删替换
                    # 替换是dp[i-1][j-1] 删除 dp[i-1][j] 插入dp[i][j-1]
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
        return dp[m][n]

```