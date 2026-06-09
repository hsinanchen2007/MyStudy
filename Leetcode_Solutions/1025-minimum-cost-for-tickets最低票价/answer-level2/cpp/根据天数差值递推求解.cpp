基于以下递推公式求解：
1. dp[i]表示旅行到days[i]天需要的最小费用
2. 对于j<i，且可以用一张票从days[j]旅行到days[i]的情况
    i. days[i]-days[j] < 30，dp[i] = min(dp[i], dp[j-1]+costs[2]);
    ii. days[i]-days[j] < 7，dp[i] = min(dp[i], dp[j-1]+costs[1]);
    iii. days[i]-days[j] < 1，dp[i] = min(dp[i], dp[j-1]+costs[0]);
3. 边界判断，需考虑
```
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        int m = min(costs[0], min(costs[1], costs[2]));
        dp[0] = m;
        for(int i=1;i<n;i++) {
            dp[i] = dp[i-1] + m;
            for(int j=i-1;j>=0;j--) {
                if(days[i]-days[j]>=30) break;
                if(days[i]-days[j]<1) dp[i] = min(dp[i], (j==0?0:dp[j-1])+costs[0]);
                if(days[i]-days[j]<7) dp[i] = min(dp[i], (j==0?0:dp[j-1])+costs[1]);
                dp[i] = min(dp[i], (j==0?0:dp[j-1])+costs[2]);
            }
            // cout<<i<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};
```
