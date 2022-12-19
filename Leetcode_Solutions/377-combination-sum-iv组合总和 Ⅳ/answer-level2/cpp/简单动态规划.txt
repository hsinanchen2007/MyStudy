### 解题思路
溢出真烦

### 代码

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<unsigned long long> dp(target+1, 0);
        // 用 vector<int> dp(target+1, 0); 有溢出错误
        dp[0] = 1;
        for (int i = 1; i <= target; i++){
            for (auto num : nums){
                if (i >= num) dp[i] += dp[i-num];
                else break;
            }
        }
        return dp[target];
    }
};
```