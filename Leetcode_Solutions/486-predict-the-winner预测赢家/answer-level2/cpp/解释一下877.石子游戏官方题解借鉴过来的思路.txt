1. 设dp[i][j]游戏从第i个拿到j个时先手玩家比后手玩家多拿的分数
2. 如果是先手玩家的轮次，他应当拿最大的那一个以扩大他的优势dp[i][j]
3. 如果是后手玩家的轮次，他也应当拿最大的那一个以减少先手玩家的优势dp[i][j]
4. 当拿完所有的分数,dp[0][nums.size()-1]就表示了先手玩家与后手玩家总分数之差，如果大于等于0就获胜
5. 如何判断是先手玩家还是后手玩家的轮次呢？如果当前需要计算拿第i个到第j个，那么这之间有j-i+1个，于是已经拿过的是N-(j-i+1)个，当前要拿的是N-(j-i+1)+1 = N-j+i;任何一个数+i或者-i的奇偶性一致所以等于N+j+i是这样来的
6. 菜鸡看了半天877的官方题解，很抽象，推荐这个小姐姐的做法！盛夏与微风[@zxy0917](/u/zxy0917/)
```
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for (int i = nums.size()-1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if((j+i+nums.size()) & 1){
                    dp[i][j] = max(nums[i] + dp[i+1][j], nums[j] + dp[i][j-1]);
                } else{
                    dp[i][j] = min(-nums[i] + dp[i+1][j], -nums[j] + dp[i][j-1]);
                }
            }
        }
        return dp[0][nums.size()-1] >= 0;
    }
};
```
