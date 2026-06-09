时间复杂度 O(knlogn)
```
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<long> dp(nums.size());
        vector<long> prefix_sum(nums.size() + 1);
        prefix_sum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
            dp[i] = prefix_sum[i + 1];
        }
        
        for (int k = 2; k <= m; k++) {
            int right = nums.size() - 2;
            for (int i = nums.size() - 1; i > 0; i--) {
                int left = 0, mid;
                right = std::min(right, i - 1);
                while (left + 1 < right) {
                    mid = left + (right - left) / 2;
                    if (dp[mid] < prefix_sum[i + 1] - prefix_sum[mid + 1]) {
                        left = mid;
                    } else if (dp[mid] >= prefix_sum[i + 1] - prefix_sum[mid + 1]) {
                        right = mid;
                    } else {
                        break;
                    }
                }
                dp[i] = std::min(std::max(prefix_sum[i + 1] - prefix_sum[right + 1], dp[right]), std::max(prefix_sum[i + 1] - prefix_sum[left + 1], dp[left]));
            }
        }
        return dp[nums.size() - 1];
    }
};
```
