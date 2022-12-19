### 解题思路
dp[i]设为以c = s[i]为结尾的有效括号长度，c='('是dp[i]=0;c=')'分两种情况：
1.s[i-1]为'(',则长度应为前面有效长度+2，即dp[i] = dp[i-2-1]+2
2.s[i-1]为')',则先判断dp[i-1]的长度前面的那个字符，若为'('，说明匹配成功，则长度应为dp[i-2-1]+2加上前面的有效长度dp[i-dp[i-1]-2]；若为')'，则匹配失败，dp[i]=0；
3.考虑上边界条件即可

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        if(s.length()<2)
            return 0;
        int res = 0;
        int[] dp = new int[s.length()];
        for(int i =1;i<s.length();++i){
            if(s.charAt(i)==')'){
                if(s.charAt(i-1)=='(')
                    dp[i] = i>1?dp[i-2]+2:2;
                else
                    dp[i] = i-dp[i-1]<1?0:s.charAt(i-dp[i-1]-1)==')'?0:i-dp[i-1]>1?dp[i-1]+dp[i-dp[i-1]-2]+2:dp[i-1]+2;
            }
            res = Math.max(res,dp[i]);
        }
        return res;
    }
}
```