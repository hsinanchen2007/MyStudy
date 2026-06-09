dp[i]:以i结尾的最长有效括号  
dp从1开始，字符串从0开始  
4ms,9.5MB  
```
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();if(n==0)return 0;
        vector<int>dp(n+1,0);int ans=0;
        for(int i=2;i<=n;i++){
            if(s[i-1]==')'){
                if(s[i-2]=='('){
                    dp[i]=2+dp[i-2];
                }else{
                    if(i-dp[i-1]-2>=0&&s[i-dp[i-1]-2]=='(')
                        dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2];
                }
            }
            //cout<<i<<" "<<dp[i]<<endl;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
```