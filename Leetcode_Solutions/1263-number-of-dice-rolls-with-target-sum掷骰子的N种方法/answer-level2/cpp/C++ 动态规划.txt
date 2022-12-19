### 解题思路
`dp[i][j]`表示用第0~i个骰子投掷出总和为j的所有的情况，则转移方程为

`dp[i][j] = dp[i-1][j-1]+...+dp[i-1][j-f]`

即第i个骰子分别掷出1 ~ f时，需要前i-1个骰子共分别掷出j-1 ~ j-f

此外，要注意细节，不要越界（见注释）
### 代码

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    int numRollsToTarget(int d, int f, int target) {
        int bottom = d;//可以掷出的最小值
        int top = d*f;//可以掷出的最大值
        if(target < bottom || target > top)
            return 0;
        if(d == 1 || target == bottom || target == top)
            return 1;
        vector<vector<int>> dp(d, vector<int>(target+1, 0));
        for(int i = 1; i <= min(f, target); i++)//注意取min
            dp[0][i] = 1;
        for(int i = 1; i < d; i++)//掷第i个骰子
            for(int j = i+1; j <= min(target, (i+1)*f); j++)//前i+1个骰子可能掷出的总和，注意取min
                for(int k = 1; k <= min(f, j); k++)//骰子的可能取值，注意取min
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
        return dp[d-1][target];
    }
};
```