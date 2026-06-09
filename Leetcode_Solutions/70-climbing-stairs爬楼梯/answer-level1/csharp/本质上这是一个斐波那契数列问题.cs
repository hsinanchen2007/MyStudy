### 解题思路

找到f(n)的数学函数通式 `f(n) = f(n-1) + f(n-2)`,
所以本质上这是一个斐波那契数列问题。

### 程序实现

```C#
public class Solution {
    public int ClimbStairs(int n) {
        if(n < 2){
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```