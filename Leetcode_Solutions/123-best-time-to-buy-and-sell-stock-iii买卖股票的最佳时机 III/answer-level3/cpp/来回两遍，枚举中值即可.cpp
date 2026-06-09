有一场CodeForces div3的D2就是这种思路
class Solution {
public:
    int dp1[30010], dp2[30010];
    int maxProfit(vector<int>& p) {
        int len = p.size();
        if(len == 0 || len == 1){
            return 0;
        }
        int now = p[0];
        dp1[0] = 0;
        for(int i = 1; i < len; ++i){
            now = min(now, p[i]);
            dp1[i] = max(dp1[i - 1], p[i] - now);
        }
        dp2[len - 1] = 0;
        now = p[len - 1];
        for(int i = len - 2; i >= 0; --i){
            now = max(now, p[i]);
            dp2[i] = max(dp2[i + 1], now - p[i]);
        }
        int ans = max(dp1[len - 1], dp2[0]);
        for(int i = 0; i < len - 1; ++i){
            ans = max(ans, dp1[i] + dp2[i + 1]);
        }
        return ans;
    }
};