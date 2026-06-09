```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        vector<pair<int,int>> dp;
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            if(nums[i]-nums[0]==0) dp.push_back(pair<int,int>(1,nums[i]-nums[0]));
            else dp.push_back(pair<int,int>(2,nums[i]-nums[0]));
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if((nums[i]-nums[j])*dp[j].second<0) 
                {
                    if(dp[j].first+1>dp[i].first) 
                    {
                        dp[i].first=dp[j].first+1;
                        dp[i].second=nums[i]-nums[j];
                    }
                }
            }
            ans=max(ans,dp[i].first);
        }
        return ans;
    }
};
```
