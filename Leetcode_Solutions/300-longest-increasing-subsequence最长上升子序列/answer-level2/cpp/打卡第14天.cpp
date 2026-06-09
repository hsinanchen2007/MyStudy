```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int s = nums.size();
        if(!s) return 0;
        vector<int> dp(s, 1);
        for(int i=0;i<s;i++){
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
       

    }
};
```
