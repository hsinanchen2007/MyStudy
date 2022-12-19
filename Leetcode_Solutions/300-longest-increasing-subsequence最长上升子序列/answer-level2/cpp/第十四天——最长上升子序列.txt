### 解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxL = 0;
        vector<int> dp(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0 ; j < i; j++)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            maxL = max(dp[i], maxL);
        }
        return maxL;
    }
};
```



