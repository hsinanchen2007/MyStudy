```
//执行用时 :48 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
#define mod 1000000007
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d+1][target+1];//置i次达到j有多少组合数
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=f&&i<=target;i++) dp[1][i] = 1;//初始化
        for(int i=1;i<=d;i++) {
            for(int j=1;j<=target;j++) {
                for(int k=1;k<=f&&j>=k;k++) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-k])%mod;
                }
            }
        }
        return dp[d][target];
    }
};
```
