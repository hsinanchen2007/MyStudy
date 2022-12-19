### 解题思路
参考了题解和评论，发现对于备忘录的构建的解释并不全。
#### 初始化 
dp(备忘录)初始化函数是字符串s的前0个与字符串第j个是否匹配，所以这里只要*中断了后续都是false.
#### 备忘录更新
当时p[j]=='*'这里其实分情况考虑的：
* 当匹配空字符串时，dp[i][j] = dp[i][j-1] 表示当p[j]=='*',s前i个与p前j个匹配==s前i个与p前j-1个匹配；
* 当匹配s[i]时，这里实际分为两个情况第一次匹配和第n次匹配，重点是第一次匹配，如果dp[i][j]是第一次匹配这里dp[i][j] = dp[i-1][j-1]，而由于是第一次匹配，所以dp[i-1][j]表示匹配空字符串，那么dp[i-1][j]==dp[i-1][j-1].如果是多次匹配则dp[i][j] = dp[i-1][j]就很好理解。
### 代码

```cpp
class Solution{
public:
    bool isMatch(string s,string p){
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                //cout<<i<<j<<endl;
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                    //pr(dp);
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                    //pr(dp);
                }
                
            }
        }
        return dp[m][n];
    }
//    void pr(vector<vector<bool>> res){
//        for(int i=0;i<res.size();i++){
//            for(int j=0;j<res[0].size();j++){
//                cout<<res[i][j];
//            }
//            cout<<endl;
//        }
//    }
};
```