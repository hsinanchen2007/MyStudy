S = "rabbbit", T = "rabbit":
  r a b b i t
r 1 0 0 0 0 0 
a 1 1 0 0 0 0 
b 1 1 1 0 0 0 
b 1 1 2 1 0 0 
b 1 1 3 3 0 0 
i 1 1 3 3 3 0 
t 1 1 3 3 3 3 


S = "babgbag", T = "bag":
  b a g 
b 1 0 0 
a 1 1 0 
b 2 1 0 
g 2 1 1 
b 3 1 1 
a 3 4 1 
g 3 4 5

代码如下：
```
class Solution {
    public int numDistinct(String s, String t) {
        if(s.length() < t.length()) return 0;
        if(t.length() == 0) return 1;
        //动态规划
        int slen = s.length(), tlen = t.length();
        int[][] dp = new int[slen][tlen];

        //判断第一个元素
        dp[0][0] = s.charAt(0) == t.charAt(0) ? 1 : 0;

        //判断第一列
        for (int i = 1; i < slen; i++) {
            if(s.charAt(i) == t.charAt(0)){
                dp[i][0] = dp[i - 1][0] + 1;
            }else{
                dp[i][0] = dp[i - 1][0];
            }
        }

        //判断第一行
        for (int j = 1; j < tlen; j++) {
            dp[0][j] = 0;
        }

        //递推转移公式
        for (int i = 1; i < slen; i++) {
            for (int j = 1; j < tlen; j++) {
                if(s.charAt(i) == t.charAt(j)){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[slen - 1][tlen - 1];
    }
}
```
