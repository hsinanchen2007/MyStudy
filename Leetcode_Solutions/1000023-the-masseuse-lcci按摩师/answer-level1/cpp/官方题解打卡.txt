### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int)nums.size();
        if (!n) return 0;
        int dp0 = 0, dp1 = nums[0];

        for (int i = 1; i < n; ++i){
            int tdp0 = max(dp0, dp1); // 计算 dp[i][0]
            int tdp1 = dp0 + nums[i]; // 计算 dp[i][1]

            dp0 = tdp0; // 用 dp[i][0] 更新 dp_0
            dp1 = tdp1; // 用 dp[i][1] 更新 dp_1
        }
        return max(dp0, dp1);
    }
};
```