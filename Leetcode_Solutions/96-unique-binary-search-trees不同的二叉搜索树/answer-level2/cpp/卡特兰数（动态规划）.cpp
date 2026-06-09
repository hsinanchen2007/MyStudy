### 解题思路
主要思路是：二叉树种类的个数等于左子树种类乘以右子树种类个数
n = 0或n = 1时，种数为1
n >= 2时，有dp[2] = dp[0] * dp[1] + dp[1] * dp[0]
dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0]
于是得到递推式 dp[i+1] = ∑dp[j]*dp[i-j],0<=j<=i
### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1] = {0};
        dp[0] = dp[1] = 1;
        for(int i = 2;i <= n;++i){
            for(int j = 0;j <= i-1;++j){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
```