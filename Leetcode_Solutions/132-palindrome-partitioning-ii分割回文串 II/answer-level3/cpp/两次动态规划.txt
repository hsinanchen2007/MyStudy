我们要求出的是最少的切割原字符串为回文子串的次数。
分两步
1.利用动态规划求出字符串中子串的回文情况
2.根据子串的回文情况求出最短切割次数

对于第一步，不再赘述。
第二步：
res[i] 表示将[0:i)划分为回文子串的时间

则res[i]=min(res[i],1+res[j]) j∈[0:i-1]
且str[j:i)为回文子串
```
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>dp(s.size()+1,vector<bool>(s.size()+1));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            dp[i][i+1]=true;
        }
        dp[n][n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=dp[i][j]||(s[i]==s[j-1]&&dp[i+1][j-1]);
            }
        }
        //res[i]表示将[0,i)划分为回文子串花费的时间.
        vector<int>res(n+1,INT_MAX);
        res[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j][i]){
                    res[i]=min(res[i],1+res[j]);
                }
            }
        }
        return res[n]-1;
    }
};
```
