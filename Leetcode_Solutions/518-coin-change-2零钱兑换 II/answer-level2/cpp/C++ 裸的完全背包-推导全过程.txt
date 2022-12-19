```
class Solution {
public:
    //集合状态表示 dp[i][j] 表示由前i种硬币组成金额为j的方案数
    //状态计算 考虑dp[i][j]的最后一步 即第i种硬币选几个从而凑成金额j 假设选k个 k = 0,1,...,j/c[i]
    //因此 dp[i][j] = dp[i-1][j] + dp[i-1][j-c[i]] + ...dp[i-1][j-k*c[i]]
    //此时为O(N^3)，需要优化 
    //发现  dp[i][j-c[i]] = dp[i-1][j-c[i]]+dp[i-1][j-2*c[i]],..dp[i-1][j-k*c[i]]
    //故而 dp[i][j] = dp[i-1][j]+dp[i][j-c[i]] O(N^2)
    //所求答案为 dp[n][target];//n种硬币组成金额为target的方案
    //边界 dp[..][0] = 1 //组成金额0只能都不选 只有一种方案数
    //可继续优化 因为只和上一次状态有关，可以使用滚动数组
    //而需要 第i层的 j-c[i] < j 所以 每次计算时需要用到这一层之前算过的值 所以应该从左往右算
    // dp[j] = dp[j]+dp[j-c[i]]);
    // 边界dp[0]  = 1;//凑0的方案为1,即都不选
    int change(int target, vector<int>& c) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= c.size(); i++){//选前i种硬币时
            for(int j = c[i-1]; j <= target; j++){
                dp[j] += dp[j-c[i-1]];
            }
        }
        return dp[target];
    }
};
```
