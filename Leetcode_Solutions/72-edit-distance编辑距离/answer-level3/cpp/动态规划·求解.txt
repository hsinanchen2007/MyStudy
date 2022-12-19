### 解题思路
对于动态规划求解的方法还是老套路，我们肯定要先建立一张dp表格一次来记录每一步的情况，因为考虑到字符串为空的情况，将dp多初始化一行一列。
在题的求解过程中我们要考虑到以下问题：
1.word1[i-1]=word2[j-1]的时候 dp[i][j]=dp[i-1][j-1],至于为什么这样大家看了这个伪代码应该会想的明白
2.当word1[i-1]!=word2[j-1]的时候有以下3种操作
   (1)当进行替换操作的时候， dp[i][j]=dp[i-1][j-1]+1  加1是因为执行这种操作的时候就已经额外操作一次了
   (2)当插入的时候，dp[i][j]=dp[i][j-1]+1
   (3)当删除的时候，dp[i][j]=dp[i-1][j]+1
   当然以上三种伪代码情况只是单独考虑的时候，但是我们要综合一下执行那种操作，所需次数最少，所以min(dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1)
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
         int m=word1.length();
         int n=word2.length();
          vector<vector<int>>dp(m+1,vector<int>(n+1,0));
           for(int i=0;i<=n;i++) //初始化第一行 这一行是空word1 与word2匹配
           {
               dp[0][i]=i;
           }
            for(int i=0;i<=m;i++)//初始化第一列 这一列是word1 与空word2匹配
           {
               dp[i][0]=i;
           }
           for(int i=1;i<=m;i++)
           {
               for(int j=1;j<=n;j++)
               {
                  
                       if(word1[i-1]==word2[j-1]) //字符相同时的操作
                       {
                           dp[i][j]=dp[i-1][j-1];
                       }
                       else //字符不同时的，插入，删除，替换 三种操作
                       {
                          dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
                          
                       }
               }
           }
           return dp[m][n];
    }
};
```