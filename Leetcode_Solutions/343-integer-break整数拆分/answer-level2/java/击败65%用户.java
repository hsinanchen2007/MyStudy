### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int integerBreak(int n) {
        // 几种一目了然的情况
        // 这几种情况都是自身大于分解
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        // 用于存储正整数到n时最大的乘积
        int[] dp = new int[n+1];
        // 分解到1，2，3就不需要继续分解了
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;      
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){
                dp[i] = Math.max(dp[j] * dp[i-j], dp[i]);
            }
        }
        return dp[n];

    }
}
```