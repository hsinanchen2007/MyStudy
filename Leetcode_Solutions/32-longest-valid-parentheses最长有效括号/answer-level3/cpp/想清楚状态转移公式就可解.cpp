### 解题思路
有效括号只会以）结尾
维护以i结尾的最长有效括号
俩种情况：
1：....()    dp[i]=dp[i-2]+2    i>2 && s[i]==')' && s[i-1]=='(' 
2: ..((...))   dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2  s[i]==')' && s[i-1]==')'
### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.length()){
            return 0;
        }
        int dp[s.length()];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==')' && s[i-1]=='('){
                if(i-2>=0){
                    dp[i]=dp[i-2]+2;
                }else{
                    dp[i] = 2;
                }
                
            }
            else if(s[i]==')' && s[i-1]==')'){
                if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                    if(i-dp[i-1]-2>=0){
                        dp[i]=dp[i-dp[i-1]-2]+dp[i-1]+2;
                    }
                    else{
                        dp[i]=dp[i-1]+2;
                    }
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    } 
};
```