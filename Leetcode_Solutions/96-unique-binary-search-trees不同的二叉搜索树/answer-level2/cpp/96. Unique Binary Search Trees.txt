### 解题思路
这是目前见到的唯一一个状态表达式是一维表达式，但状态的求解却非常数时间的dp.

### 代码

```cpp
class Solution {
public:
    //dp[n]表示取到n的时候，一共有多少BST。
    //F[i,n]表示取到n的时候,以第i个数字为根节点的BST，有多少种表示方法。
    //dp[n] = F[1,n] + F[2,n] + ... + F[n,n]
    //F[i,n] = dp[i-1] * dp[n-i]
    //dp[n]  = dp[0]*dp[n-1] + dp[1]*dp[n-2] + ... + dp[n-1][0]
    //以上dp[i]的每个状态求解时间都不是常数，而是依赖i值大小来的循环求解（代码内侧循环）。
    int numTrees(int n) {
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
```