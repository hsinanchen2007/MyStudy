用dp[i][j]表示S中前i个字符能组成T中前j的字符串的个数。
如果当前s[i]==t[j],则dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
如果当前s[i]!=t[j],则dp[i][j]=dp[i-1][j].
```
class Solution {
public:
    int numDistinct(string &s, string &t) {
        int ls=s.length(), lt=t.length();
        vector<vector<long> > dp(ls+1,vector<long>(lt+1,0));
        for(int i=0; i<ls; ++i){
            dp[i][0]=1;
            for(int j=0; j<lt; ++j)
                dp[i+1][j+1]=dp[i][j+1]+(s[i]==t[j]?dp[i][j]:0);
        }
        return dp[ls][lt];
    }
};
```
仔细观察上面代码，第一层循环，只需要当前第i+1行和前一行（第i行）。所以可以使用滚动数组进行状态压缩。Time O(m*n)，Space O(n).
```
class Solution {
public:
    int numDistinct(string &s, string &t) {
        int ls=s.length(), lt=t.length();
        vector<vector<long> > dp(2,vector<long>(lt+1,0));
        dp[0][0]=dp[1][0]=1;
        for(int i=0; i<ls; ++i)
            for(int j=0; j<lt; ++j)
                dp[(i+1)&1][j+1]=dp[i&1][j+1]+(s[i]==t[j]?dp[i&1][j]:0);
        return max(dp[0][lt],dp[1][lt]);
    }
};
```

