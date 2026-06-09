### 解题思路
1. 递推公式F(n) = F(n-1) + F(n-2);
2. 利用数组保存中间状态，避免重复计算

### 时间复杂度
只需要一次遍历操作，所以时间复杂度为O(n)


### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n <= 2) return n;
        int []dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
```