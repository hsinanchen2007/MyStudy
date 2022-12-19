### 代码

```java
/*

dp_max[i] 指的是以第 i 个数结尾的 乘积最大 的连续子序列
dp_min[i] 指的是以第 i 个数结尾的 乘积最小 的连续子序列

if nums[i] >= 0:
dp_max[i] = max(dp_max[i-1] * nums[i], nums[i]);
dp_min[i] = min(dp_min[i-1] * nums[i], nums[i]);

if (nums[i] < 0)
dp_max[i] = max(dp_min[i-1] * nums[i], nums[i]);
dp_min[i] = min(dp[max[i-1] * nums[i], nums[i]);

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(n+1), dp_min(n+1);
        dp_max[0] = dp_min[0] = 1;
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int x = nums[i-1];
            if (x >= 0) {
                dp_max[i] = max(dp_max[i-1] * x, x);
                dp_min[i] = min(dp_min[i-1] * x, x);
            } else {
                dp_max[i] = max(dp_min[i-1] * x, x);
                dp_min[i] = min(dp_max[i-1] * x, x);
            }
            ret = max(ret, dp_max[i]);
        }
        return ret;
    }
};
```