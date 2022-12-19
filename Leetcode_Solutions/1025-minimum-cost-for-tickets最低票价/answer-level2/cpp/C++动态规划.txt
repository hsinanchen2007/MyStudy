### 解题思路
动态规划 dp[i]=min{dp[i-1]+costs[0],dp[i-7]+costs[1],dp[i-30]+costs[2]}

### 代码

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int l=days.size();
        int max=days[l-1]+1;
        int dp[max];
        for(int i=0;i<max;i++){
            dp[i]=0;
        }
        for(int i=1;i<max;i++){
            if(!isin(i,days)) dp[i]=dp[i-1];
            else{
                int num1=dp[i-1]+costs[0];
                int num2= (i>=7)?dp[i-7]+costs[1]:costs[1];
                int num3= (i>=30)?dp[i-30]+costs[2]:costs[2];
                dp[i]=min(num1,min(num2,num3));
            }
        }
        for(int i=0;i<max;i++){
            cout<<dp[i]<<" ";
        }
        return dp[max-1];
    }
    int isin(int k,vector<int>& days){
        for(int i=0;i<days.size();i++){
            if(days[i]==k) return 1;
        }
        return 0;
    }
};


