**状态量dp[i][j]表示将s.substr(i,j-1+1)变成回文串的最少步数，如果s[i]==s[j],那么dp[i][j]=dp[i+1][j-1],否则我们就分别考虑dp[i+1][j]和dp[i][j-1],选取min(dp[i+1][j],dp[i][j-1])+1作为结果。**
```
class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),INT_MAX));
        //dp初始化
        for(int i=0;i<dp.size();i++)
            dp[i][i]=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
                dp[i][i+1]=0;
            else
                dp[i][i+1]=1;
        }
        //从长度为3的字符串开始
        for(int length=3;length<=s.size();length++)
        {
            for(int i=0;i+length-1<s.size();i++)
            {
                int j=i+length-1;
                if(s[i]==s[j])
                    dp[i][j]=min(dp[i+1][j-1],dp[i][j]);
                else
                    dp[i][j]=min(1+min(dp[i+1][j],dp[i][j-1]),dp[i][j]);
            }
        }
        return dp[0][s.size()-1];
    }
};
```
本来一看才500的数据量，想直接暴力深搜来着，结果超时了，想改用dp发现已经没时间了TAT，果然还是自己太菜了
