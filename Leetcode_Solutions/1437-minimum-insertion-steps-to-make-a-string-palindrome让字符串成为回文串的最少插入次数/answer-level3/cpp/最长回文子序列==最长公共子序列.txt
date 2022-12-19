这题的本质是求最长回文子序列，用长度相减即是最小插入数。
求一个字符串的最长回文子序列又可以等效转化为求**该字符串**与**其反转字符串**这两者的***最长公共子序列***。
所以只要你会做那道经典的dp题LCS，这题就是披了个马甲。
这题其实也能用最短编辑距离的方法来做，但是我的方法都超时了，还请大佬赐教。
```
class Solution {
public:
    int dp[501][501];    

    int minInsertions(string s) {
        int n = s.size();
        string cp(s);
        reverse(cp.begin(),cp.end()); //反转
        
        for(int i=1;i<=n;i++) // 最长公共子序列
            for(int j=1;j<=n;j++)
                if( s[i-1] == cp[j-1] ) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

        return n-dp[n][n] ;
    }
};
```
