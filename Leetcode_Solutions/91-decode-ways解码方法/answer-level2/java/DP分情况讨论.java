### 解题思路
分情况讨论

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        Set<Integer> hash = new HashSet<>();
        int[] str = stringToInts(s);
        int res = 0;
        int[] dp = new int[str.length];
        if (str[0] == 0) {
            return 0;
        } else {
            dp[0] = 1;
        }
        for (int i = 1;i < str.length; i++) {
            if (str[i] == 0) {
                if ((str[i] + str[i - 1] * 10) > 26) {
                    return 0;
                } else if (str[i - 1] == 0) {
                    return 0;
                } else if (i == 1){
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i - 2];
                }
                continue;
            }
            if (i == 1) {
                if ((str[i] + str[i - 1] * 10) < 27) {
                    dp[i] = 2;
                } else {
                    dp[i] = 1;
                }
                
            } else {
                if ((str[i] + str[i - 1] * 10) < 27) {
                    dp[i] = (str[i - 1] == 0 ? 0 : dp[i - 1]) + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[str.length - 1];
    }



    public static int[] stringToInts(String s){
        int[] n = new int[s.length()]; 
        for(int i = 0;i<s.length();i++){
            n[i] = Integer.parseInt(s.substring(i,i+1));
        }
        return n;
    }
}
```