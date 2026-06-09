### 解题思路
记得之前似乎做过这题，想了一会儿之后决定用动态规划试一把。在不知道amount范围和coins大小的情况下，动态规划算法的时间复杂度为o(amount*coins.size())。
所以还是有点心虚。但是提交之后发现原来一个月前做过这题，当时最后用的是递归算法几经删改以548ms通过的。从这里看来自己还是有学到点东西的。

### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1;i <= amount;i++) dp[i] = -1;
        for(int i = 1;i <= amount;i++){
            int min = INT_MAX;
            for(int j = 0;j < coins.size();j++){
                if(i - coins[j] >= 0 && dp[i-coins[j]] != -1){
                    min = min > dp[i-coins[j]] ? dp[i-coins[j]] : min;
                }
            }
            dp[i] = min == INT_MAX ? -1 : min+1;
        }
        return dp[amount];
    }
};
```