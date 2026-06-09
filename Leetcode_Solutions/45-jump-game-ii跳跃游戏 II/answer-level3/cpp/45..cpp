无脑搜就完事了，16ms
```
class Solution {
public:
    vector<long long>dp;//以i为起点的最小步数
    int jump(vector<int>& nums) {
        int n=nums.size();dp.resize(n+1,0);
        if(n==0)return 0;
        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=n-1)
                dp[i]=1;//初始化
        }dp[n-1]=0;
        return dfs(0,nums);
    }
    long long dfs(int x,vector<int>& nums){
        if(x==nums.size()-1)return 0;
        if(nums[x]==0)return dp[x]=INT_MAX;//剪枝
        if(dp[x])return dp[x];
        long long ans=INT_MAX;
        for(int j=x+1;j<=x+nums[x];j++){
            if(j+nums[j]<=x+nums[x])continue;//重要剪枝
            ans=min(ans,1+dfs(j,nums));
        }
        return dp[x]=ans;
    }
};
```
