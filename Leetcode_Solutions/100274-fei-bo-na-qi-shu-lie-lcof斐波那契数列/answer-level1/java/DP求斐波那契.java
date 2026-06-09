### 解题思路
Dp带备忘录
防止int溢出，每次求和取余
利用两个变量pre cur可以保证空间复杂度只为O(1)

### 代码

```java
class Solution {
    public int fib(int n){
        if(n <= 1){
            return n;
        }
        int pre = 0;
        int cur = 1;
        int sum = 0;
        for(int i = 2; i < n + 1; i++){
            sum =  (pre + cur) % 1000000007;
            pre = cur;
            cur = sum;
        }
        return sum;
    }
    /*
    public int fib(int n){
        if(n <= 1){
            return n;
        }
        int[] dp = new int[n + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i] = 0;
        }
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++){
            dp[i] =  (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
    */
    /*
    private int[] dp;
    public int fib(int n) {
        dp = new int[101];
        for(int i = 0; i < n + 1; i++){
            dp[i] = 0;
        }
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++){
            if(dp[i] != 0){
                continue;
            }
            else{
                dp[i] =  (dp[i - 1] + dp[i - 2]) % 1000000007;
            }
        }
        return dp[n];
    }
    */
}
```