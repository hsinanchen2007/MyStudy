```
class Solution {
public:
    int massage(vector<int>& nums) {
        int sz = nums.size();
        if(sz ==0) return 0;
        vector<int>dp(sz,0);
        dp[0] = nums[0];
     // dp 数组含义，当前时间的最大分钟数。
        for(int i=1;i<sz;i++){ 
            if(i >=2)
                dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
            else
                dp[i] = max(nums[i],nums[i-1]);
        }
        return dp[sz-1];
    }
};
```
