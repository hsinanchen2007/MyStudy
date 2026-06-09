比较容易想到我们要找的目的字符串由三部分组成：两个字符串的最长公共子序列LCS+第一个字符串除去LCS之后的序列+第二个字符串除去LCS之后的序列。
求LCS是经典的动态规划题目，所以此题相对的难点在于由LCS去构建目的字符串。
同一个字符串中的字符的相对顺序不可改变，所以我们可以用字符串与LCS比较来确定字符的相对位置。
```
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        //求LCS
        vector<vector<string>> dp(n+1,vector<string>(m+1));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+str1[i-1];
                else
                    dp[i][j]=(dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1]);
            }
        //构建目的字符串
        string ans,lcs=dp[n][m];
        int i=0,j=0;
        //按照同一个字符串内的字符相对于LCS的顺序构建目的字符串
        for(char ch:lcs)
        {
            //不同字符串的字符相对顺序无关，所以先遍历str1和先遍历str2都可以
            while(i<n&&str1[i]!=ch)
                ans+=str1[i++];
            while(j<m&&str2[j]!=ch)
                ans+=str2[j++];
            ans+=ch,++i,++j;
        }
        //加上每个字符串在LCS之后的字符
        return ans+str1.substr(i)+str2.substr(j);
    }
};
```
这种做法比较好理解，但时间效率并不高。