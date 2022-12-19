简单动态规划，枚举一年中每一天。如果这一天没有出去旅游，则dp[i]=dp[i-1]；如果这一天有出去旅游，则取min(买天的票:dp[i-1]+cost[0],买7天的票:dp[i-7]+cost[1],买30天的票:dp[i-30]+cost[2])。
```
class Solution {
public:
    static const int maxn=366;
    int dp[maxn];
    bool judge(vector<int>& days,int x){
        int pos=lower_bound(days.begin(),days.end(),x)-days.begin();
        if(days[pos]!=x) return false;
        else return true;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=days[days.size()-1];i++){
            if(!judge(days,i)) dp[i]=dp[i-1];
            else{
                int x,y,z;
                x=(i-1)>=0?dp[i-1]+costs[0]:costs[0];
                y=(i-7)>=0?dp[i-7]+costs[1]:costs[1];
                z=(i-30)>=0?dp[i-30]+costs[2]:costs[2];
                dp[i]=min(min(x,y),z);
            }
        }
        return dp[days[days.size()-1]];
    }
};
```
