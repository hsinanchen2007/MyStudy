### 解题思路
dp[i][j]表示从i之前的某一个位置能够以j步跳至i位置并且能够从第一个石头跳至i位置

### 代码

```java
class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        boolean dp [][] = new boolean[n][n];
        if (stones[1] - stones[0] == 1) dp[1][1] = true;
        for (int i = 2; i < n; i++){
            for (int j = 0; j < i; j++){
                int diff = stones[i] - stones[j];
                if (diff < n){
                    if (diff + 1 < n){
                        dp[i][diff] = dp[j][diff-1] || dp[j][diff] || dp[j][diff+1];
                    }
                    else dp[i][diff] = dp[j][diff-1] || dp[j][diff];
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            if (dp[n-1][i]) return true;
        }
        return false;
    }
}
```