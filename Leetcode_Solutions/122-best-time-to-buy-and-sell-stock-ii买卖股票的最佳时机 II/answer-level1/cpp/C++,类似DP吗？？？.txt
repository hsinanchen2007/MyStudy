```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        if(n==0)return 0;
        vector<int>dp(n,0);
        int min_num=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>min_num){
                dp[i]=prices[i]-min_num;
                min_num=prices[i];
            }else{
                min_num=prices[i];
            }
        }
        for(int i=0;i<n;i++){
            ans+=dp[i];
        }
        return ans;
    }
};
```
