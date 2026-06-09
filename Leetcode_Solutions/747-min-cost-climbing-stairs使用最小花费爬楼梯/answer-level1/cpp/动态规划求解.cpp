### 解题思路
1. dp[i] 为上到第i个台阶最小花费的力量
2. 寻找dp[i]和dp[i-1],dp[i-2]的关系，关系为min(dp[i-1],dp[i-2])+cost[i-1],特殊情况就是从倒数一个之间跳到最后一个台阶的下一个的情况，所以的最后需要判断一下是否最后dp[len]比dp[len-1]小
3. 最后是考虑最开始 初值的问题 dp[0] = 0;dp[1] = cost[0];
### 代码
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len == 0) return 0;
        // dp[i] 为上到第i个台阶最小花费的力量
        int dp[len+2]; 
        dp[0] = 0;
        dp[1] = cost[0];

        for(int i=2;i<=len;i++){
          dp[i] = min(dp[i-1],dp[i-2])+cost[i-1];
        }
        // 注意从倒数一个之间跳到最后一个台阶的下一个的情况
        dp[len] = min(dp[len],dp[len-1]);
        return dp[len]; 
    }
};
```