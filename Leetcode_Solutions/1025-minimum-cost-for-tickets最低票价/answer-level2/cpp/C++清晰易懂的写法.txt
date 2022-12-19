```
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //如果持续天数多的票反而更便宜，那就买持续天数多的票
        if(costs[1] > costs[2]){
            costs[1] = costs[2];
        }
        if(costs[0] > costs[1]){
            costs[0] = costs[1];
        }
        //如果这一天不旅游就定为-1
        vector<int> dp(366, -1);
        for (auto &i : days) {
            dp[i] = INT32_MAX;
        }
        //第0天一定为0费用
        dp[0] = 0;
        for (int i = 1; i <= days.back(); ++i) {
            if(dp[i] != -1){
                dp[i] = min(dp[i], dp[i-1] + costs[0]);
                if(i-7 >= 0){
                    dp[i] = min(dp[i], dp[i-7] + costs[1]);
                }else{
                    //小于七天也可以买七天的票
                    dp[i] = min(dp[i], costs[1]);
                }
                if(i-30 >= 0){
                    dp[i] = min(dp[i], dp[i-30] + costs[2]);
                }else{
                    dp[i] = min(dp[i], costs[2]);
                }
            } else{
                //当天不出行就更新为前一天的花费
                dp[i] = dp[i-1];
            }
        }
        return dp[days.back()];
    }
};
```
