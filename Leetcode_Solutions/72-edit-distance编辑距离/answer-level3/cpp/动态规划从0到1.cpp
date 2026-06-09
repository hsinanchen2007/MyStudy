刚开始看题的时候有点蒙蔽，但是我想既然是字符串那么很大概率是可以动态规划的。
动态规划的题做了也有许多了，简单点的状态转移方程可以想出来，但是难一点的还是画图来的更真切.
话不多说，直接上图解释

```
	r	o	s
h	1	2	3
o	2	1	2
r	2	2	2
s	3	3	2
e	4	4	3
s	5	5	4
```
姑且先定义一个二维动态数组`dp`,`dp[i][j]`表示`Word1[:i+1]`到`word2[:j+1]`所需操作的最小步数，那么从图里边我们可以得出以下状态转移方程
- `word1[i]==word2[j]`时，`dp[i][j]=dp[i-1][j-1]`
- `word1[i]!=word2[j]`时,`dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1`;
接下来就是处理边界条件了，为了使`word1[i]==word2[j]`时，`dp[i][j]=dp[i-1][j-1]`，要初始化
`dp[0][i]=i,dp[i][0]=i`。也就是下图所示的
```
0	1	2	3
1	0	0	0
2	0	0	0
3	0	0	0
4	0	0	0
5	0	0	0
6	0	0	0

```
题解写的有点烂，最近也在慢慢的加强自己的语言表达，讲真把自己想的很清楚的表达出来也是一门艺术
```
class Solution {
public:
    int minDistance(string word1, string word2) {
//两种特殊情况的处理
        if(word1.size()==0)return word2.size();
        if(word2.size()==0)return word1.size();
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
//初始化
        for(int i=1;i<=word1.size();i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=word2.size();i++){
            dp[0][i]=i;
        }
//dp
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```
