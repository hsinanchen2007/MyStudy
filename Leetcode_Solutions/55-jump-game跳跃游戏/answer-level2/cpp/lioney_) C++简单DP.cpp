```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);   //dp[i]表示到当前节点还剩余的跳力
        for(int i=1; i<n; i++) {
            dp[i] = max(dp[i-1], nums[i-1]) - 1;
            if(dp[i] < 0 ) return false;
        }
        return true;
    }
};
```
