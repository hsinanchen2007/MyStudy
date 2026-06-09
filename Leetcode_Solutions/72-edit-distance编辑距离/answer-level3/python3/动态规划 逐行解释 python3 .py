# 题解
## 动态规划
![在这里插入图片描述](https://pic.leetcode-cn.com/4ef591f949e50e41ad0151cde08d54193bb7c167e7dc2e05f8bf5a20a856141e.png)
 1. 初试化$dp$，为$(n1+1)*(n2+1)$的全零矩阵，$n1$为$word1$的长度，$n1$为$word2$的长度
 2. 初始化第一行和第一列，如图所示：$""$表示空字符，
 	+ 第一行中，$dp[0][i]$表示空字符$""$到$word2[0,...,i]$需要编辑几次，易知空字符需要执行$i$次插入操作才能得到。因此，$dp[0][i]=i$。
 	+ 第一列中，$dp[i][0]$表示$word[0,...,i]$到空字符的编辑距离，易知$word[0,...,i]$需要执行$i$次删除操作才能得到空字符。因此，$dp[i][0]=i$。
 
 3. 遍历每一行，遍历区间$[1,n1+1)$，行号$i$：
 	+ 遍历每一列，便利区间$[1,n2+1)$，列号$j$：
 		+ 若$word1[i]==word2[j]$，如图中红色格。此时$dp[i][j]=dp[i-1][j-1]$，直接将黄色格内容复制过来。表示之前$word1[0,...,i-1]$即"hor"经过两次编辑变成了$word2[0,...,j-1]$即"ro"，并且$word1[i]==word2[j]$。所以无需修改，直接等于$dp[i-1][j-1]$
 		+ 否则，如图中绿色格所示。取蓝色格中的最小值加一。表示"r"由空字符直接添加得到。即$dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1$
 
 4. 返回$dp[n1+1][n2+1]$即可。

### 复杂度分析
 - 时间复杂度：$O\left(n1*n2\right)$
 - 空间复杂度：$O(n1*n2)$

### Python
```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1=len(word1)
        n2=len(word2)
        dp=[[0]*(n2+1) for _ in range(n1+1)]
        for i in range(n2+1):
            dp[0][i]=i
        for i in range(n1+1):
            dp[i][0]=i
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if(word1[i-1]==word2[j-1]):
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1
        return dp[-1][-1]
```