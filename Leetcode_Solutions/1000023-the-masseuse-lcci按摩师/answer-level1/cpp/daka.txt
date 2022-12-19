```
class Solution {
public:
    int massage(vector<int>& nums)
    {
        vector<int> dp(nums.size() + 2, 0);
        int k = 2;
        while(k < nums.size() + 2)
            dp[k++] = std::max(nums[k-2] + dp[k-2], dp[k-1]);
        return dp[k-1];
    }
};
```
