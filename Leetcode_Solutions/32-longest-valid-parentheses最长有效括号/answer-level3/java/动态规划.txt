### 解题思路
太难了，做了一晚上，列了太多没必要计算的情况。
参考官方，只考虑dp[i] == ')' 的时候，dp[i-1]的两种情况。dp[i-1] == ')' 时 ，再考虑dp[i-1-dp[i-1]] 的情况。（只考虑计算max有可能会变大的情况）

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        int[] dp = new int[s.length()];
        int max = 0;
        for(int i = 1 ; i< s.length() ; i ++){
            if(s.charAt(i) == ')'){
                if(s.charAt(i-1) == '('){
                    dp[i] = (i > 1 ? dp[i-2] : 0) + 2;
                }
                else if(s.charAt(i-1) == ')' && i-1-dp[i-1] >= 0){
                    if(s.charAt(i-1-dp[i-1]) == '('){
                        dp[i] = 2 + dp[i-1] + (i-2-dp[i-1] >= 0 ? dp[i-2-dp[i-1]] : 0);
                    }
                }
            }
            max = Math.max(max , dp[i]);
        }
        return max;
        
    }
}
```