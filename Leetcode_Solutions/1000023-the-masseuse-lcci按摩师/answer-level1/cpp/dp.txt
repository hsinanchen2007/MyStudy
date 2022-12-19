class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int *dp=new int[n];
        dp[0]=nums[0];
        if(n==1)return dp[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};

![image.png](https://pic.leetcode-cn.com/1809550c09219891510ac72d835b7c8702d32d40e01fa944cc6ba1e0ea5de9ba-image.png)
