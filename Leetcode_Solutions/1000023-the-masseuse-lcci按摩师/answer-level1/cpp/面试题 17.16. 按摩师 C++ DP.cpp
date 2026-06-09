### 解题思路
dp[i]表示第i天的预约和的最大值；
转移矩阵：
dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);


### 代码

```cpp
class Solution {
public:
    int massage(vector<int> &nums)
    {
        vector<int> dp = vector<int>(nums.size() + 1, 0);
        for (int i = 1; i < dp.size(); i++) {
            if (i == 1) {
                dp[i] = max(dp[i - 1], nums[i - 1]);
            }else{
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            }

        }

        return dp.back();
    }
};
```