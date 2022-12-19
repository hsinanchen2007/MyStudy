耗时1.1s, 击败5%，内存360MB，说明测试用例很变态。应该有更好的解法。
动态规划方程：

    dp[r][c] = dp[r-1][c-1] + dp[0][c]
    dp[r][c] 代表在r~c数字之和

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0) { return 0; }
        vector<vector<int>> dp(size);
        dp[0].resize(size);
        for (int i = 0; i < size; i++) { dp[0][i] = nums[i]; if(dp[0][i] >= s) { return 1; } }
        for (int r = 1; r < size; r++) {
            dp[r].resize(size);
            for (int c = r; c < size; c++) {
                dp[r][c] = dp[r-1][c-1] + dp[0][c];
                if (dp[r][c] >= s) { return r + 1; }
            }
        }
        return 0;
    }
};
```
