### 解题思路
简单思路就是算编辑距离，然后判断最短编辑距离是否大于二，虽然时间慢了点，但是如果只能改一次改成只能改 n 次，那么只需结果处修改为判断 dp[fl-1][sl-1] < n 就可以了。

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        if(first == null || second == null
        || Math.abs(first.length() - second.length()) > 2) return false;
        int fl = first.length()+1;
        int sl = second.length()+1;
        int[][] dp = new int[fl][sl];
        for(int i = 0; i < fl; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < sl; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i < fl; i++){
            for(int j = 1; j < sl; j++){
                if(first.charAt(i-1) == second.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int d1 = dp[i-1][j];
                    int d2 = dp[i][j-1];
                    int d3 = dp[i-1][j-1];
                    dp[i][j] = Math.min(d1, Math.min(d2, d3)) + 1;
                }
            }
        }
        return dp[fl-1][sl-1] < 2;
    }
}
```