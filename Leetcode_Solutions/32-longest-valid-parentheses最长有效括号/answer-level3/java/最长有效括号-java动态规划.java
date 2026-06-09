### 解题思路
其中dp[i]为下标为i时最长有效括号长度
若s为"(()"，则dp[0] = 0,dp[1] = 0,dp[2] = 2

若s为"(())",则dp[0] = 0,dp[1] = 0,dp[2] = 2,dp[3] = dp[2] +2 = 4

若s为“()(()”,则dp[0] = 0,dp[1] = 2,dp[2] = 0,dp[3] = 0,dp[4] = 2

若s为“()(())”,则dp[0] = 0,dp[1] = 2,dp[2] = 0,dp[3] = 0,dp[4] = 2,dp[5] = dp[4] + dp[1] + 2 =6
### 代码

```java
class Solution {
    
    public int longestValidParentheses(String s) {
        int s_len = s.length(),max = 0;
        int[] dp = new int[s_len];
        for(int i=1;i<s_len;i++){
            if(s.charAt(i)==')'){
                if(s.charAt(i-1)=='('){
                    dp[i] = (i>=2?dp[i-2]:0)+2;
                }else if(i-dp[i-1]>0&&s.charAt(i-dp[i-1]-1)=='('){
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            max = Math.max(max,dp[i]);
        }
        return max;
    }
    
}
```