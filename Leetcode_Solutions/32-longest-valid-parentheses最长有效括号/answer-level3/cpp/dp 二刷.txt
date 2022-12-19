```c++ []
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> dp(n,0);
        
        for(int i = 1; i < n; ++i){
            if(s[i] == '('){
                dp[i] = 0;
            }else{
                int pre = i-1- dp[i-1];
                if(pre >= 0 && s[pre] == '('){
                    if(pre > 0){
                        dp[i] = dp[i-1] + 2 + dp[pre-1];
                    }else{
                        dp[i] = dp[i-1] + 2;
                    }
                }
            }
        }
        
        for(int i = 0;i < n; ++i){
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};
```
```python []

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0 for _ in range(len(s))]
        ans = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                dp[i] = 0
            else:
                pre = i-1-dp[i-1]
                if pre >= 0 and s[pre] == '(':
                    if pre > 0:
                        dp[i] = dp[i-1] + 2 + dp[pre-1]
                    else:
                        dp[i] = dp[i-1] + 2
            
            ans = max(ans,dp[i])
        
        return ans
```
```java []
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] dp = new int[n];
        int ans = 0;
        
        for(int i = 0;i < n; ++i){
            dp[i] = 0;
        }
        for(int i = 1; i < n; ++i){
            if(s.charAt(i) == '('){
                dp[i] = 0;
            }else{
                int pre = i-1-dp[i-1];
                if(pre >= 0 && s.charAt(pre) == '('){
                    if(pre > 0){
                        dp[i] = dp[i-1] + 2 + dp[pre-1];
                    }else{
                        dp[i] = dp[i-1] + 2;
                    }
                }
            }
            ans = Math.max(ans,dp[i]);
        }
        
        return ans;
    }
}
```
