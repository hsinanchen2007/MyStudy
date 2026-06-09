
![image.png](https://pic.leetcode-cn.com/74dd9aea641bf39df2a78e326ced5e0226763edbd8ca6218cd8a06f6f8a8a7aa-image.png)

```
class Solution {
    public int uniquePaths(int m, int n) {
        
        int [][] dp = new int[m + 1][n + 1];
        dp[1][1] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(i == 1 || j == 1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                
            }
        }
        return dp[m][n];
    }
}
```
