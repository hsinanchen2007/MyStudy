### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        // s的第一个字母不可以是‘0’
        if(s.charAt(0) == '0'){
            return 0;
        }
        int n = s.length();
        // 字符串长度为1时，则只有一种可能
        if(n == 1){
            return 1;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            // 将i-1所有的组合后面一个字母，所以跟i-1的组合数相等
            if(s.charAt(i) != '0'){
                dp[i] = dp[i-1];
            }
            if(isValid(s.substring(i-1, i+1))){
                // i-2所有的组合，后面加两个字母为一组
                if(i - 2 >= 0){
                    dp[i] += dp[i-2];
                }
                else{
                    // i < 2，则只增加一种可能
                    dp[i]++;
                }
                
            }
        }
        return dp[n-1];
    }
    // 判断字符串是否在1~26之间
    private boolean isValid(String s){
        if(s.charAt(0) == '0'){
            return false;
        }
        int value = Integer.valueOf(s);
        return value > 0 && value <= 26;
    }
}
```