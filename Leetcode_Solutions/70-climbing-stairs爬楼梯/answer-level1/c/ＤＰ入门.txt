### 解题思路
边界条件：dp[1] = 1;  dp_2 = 2; i <= n
转移方程：dp[i] = dp[i-1] + dp[i-2]
### 代码

```c
//  dp[i] = dp[i-1] + dp[i-2]
int climbStairs(int n){
    if (n <= 2) return n;
    int dp_1 = 1;
    int dp_2 = 2;
    for (int i = 3; i <= n; i++)
    {
        int temp = dp_1 + dp_2;
        dp_1 = dp_2;
        dp_2 = temp;
    }
    return dp_2;
}
```